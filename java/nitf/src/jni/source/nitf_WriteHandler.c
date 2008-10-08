/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include <import/nitf.h>
#include "nitf_WriteHandler.h"
#include "nitf_JNI.h"

NITF_JNI_DECLARE_OBJ(nitf_WriteHandler)


typedef struct _WriteHandlerImpl
{
    jobject self;
} WriteHandlerImpl;


/*
 *  Private read implementation for file source.
 */
NITFPRIV(NITF_BOOL) WriteHandler_write
    (NITF_DATA * data, nitf_IOHandle io, nitf_Error * error)
{
    jclass  writeHandlerClass = NULL,
            ioHandleClass = NULL;
    jmethodID methodID = NULL;
    WriteHandlerImpl *impl = NULL;
    jobject ioHandle = NULL;
    JNIEnv *env = NULL;
    JavaVM *vm = NULL;
    int detach;

    /* cast it to the structure we know about */
    impl = (WriteHandlerImpl *) data;
    
    detach = _GetJNIEnv(&vm, &env);
    
    writeHandlerClass = (*env)->GetObjectClass(env, impl->self);
    ioHandleClass = (*env)->FindClass(env, "nitf/IOHandle");
    

    methodID = (*env)->GetMethodID(env, ioHandleClass, "<init>", "(J)V");
    ioHandle = (*env)->NewObject(env, ioHandleClass, methodID, (jlong) io);
    
    methodID = (*env)->GetMethodID(env, writeHandlerClass, "write",
                "(Lnitf/IOHandle;)V");

    /* call the Java class's write method */
    (*env)->CallVoidMethod(env, impl->self, methodID, ioHandle);

    if (detach)
        (*vm)->DetachCurrentThread(vm);
    return NITF_SUCCESS;
}


NITFPRIV(void) WriteHandler_destruct(NITF_DATA * data)
{
    jclass writeHandlerClass = NULL;
    jmethodID methodID = NULL;
    WriteHandlerImpl *impl = NULL;
    JNIEnv *env = NULL;
    JavaVM *vm = NULL;
    int detach;
    
    detach = _GetJNIEnv(&vm, &env);

    if (data)
    {
        impl = (WriteHandlerImpl *) data;
        writeHandlerClass =
            (*env)->GetObjectClass(env, (jobject) impl->self);

        /* Delete the global ref */
        (*env)->DeleteGlobalRef(env, impl->self);
        NITF_FREE(data);
    }
    
    if (detach)
        (*vm)->DetachCurrentThread(vm);
}


JNIEXPORT void JNICALL Java_nitf_WriteHandler_construct
  (JNIEnv *env, jobject self)
{
    /* make the interface */
    static nitf_IWriteHandler iWriteHandler = {
        &WriteHandler_write,
        &WriteHandler_destruct
    };
    
    nitf_WriteHandler *writeHandler = NULL;
    WriteHandlerImpl *impl = NULL;
    nitf_Error error;

    /* construct the persisent one */
    impl = (WriteHandlerImpl *) NITF_MALLOC(sizeof(WriteHandlerImpl));
    if (!impl)
    {
        _ThrowNITFException(env, "Out of memory");
        return;
    }

    /**************************************************************/
    /* THIS IS VERY IMPORTANT... WE MUST MAKE A STRONG GLOBAL REF */
    /**************************************************************/
    impl->self = (*env)->NewGlobalRef(env, self);

    writeHandler = (nitf_WriteHandler *) NITF_MALLOC(sizeof(nitf_WriteHandler));
    if (!writeHandler)
    {
        _ThrowNITFException(env, "Out of Memory");
        return;
    }
    writeHandler->data = impl;
    writeHandler->iface = &iWriteHandler;

    _SetObj(env, self, writeHandler);
}


JNIEXPORT void JNICALL Java_nitf_WriteHandler_destructMemory
  (JNIEnv *env, jobject self)
{
    nitf_WriteHandler *writeHandler = _GetObj(env, self);
    if (writeHandler)
        nitf_WriteHandler_destruct(&writeHandler);
    _SetObj(env, self, NULL);
}
