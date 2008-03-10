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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <import/nitf.h>
/* Header for class nitf_BandInfo */

#ifndef _Included_nitf_BandInfo
#define _Included_nitf_BandInfo
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     nitf_BandInfo
 * Method:    getBandEntriesPerLUT
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getBandEntriesPerLUT
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    getImageFilterCode
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getImageFilterCode
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    getImageFilterCondition
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getImageFilterCondition
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    getNumLUTs
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getNumLUTs
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    getRepresentation
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getRepresentation
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    getSubcategory
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getSubcategory
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    getLookupTable
 * Signature: ()Lnitf/LookupTable;
 */
JNIEXPORT jobject JNICALL Java_nitf_BandInfo_getLookupTable
  (JNIEnv *, jobject);

/*
 * Class:     nitf_BandInfo
 * Method:    setLookupTable
 * Signature: (Lnitf/LookupTable;)V
 */
JNIEXPORT void JNICALL Java_nitf_BandInfo_setLookupTable
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
