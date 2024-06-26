/*
 *  
 *     The contents of this file are subject to the Initial 
 *     Developer's Public License Version 1.0 (the "License"); 
 *     you may not use this file except in compliance with the 
 *     License. You may obtain a copy of the License at 
 *     https://www.firebirdsql.org/en/initial-developer-s-public-license-version-1-0/
 *
 *     Software distributed under the License is distributed on 
 *     an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either 
 *     express or implied.  See the License for the specific 
 *     language governing rights and limitations under the License.
 *
 *
 *  The Original Code was created by James A. Starkey for IBPhoenix.
 *
 *  Copyright (c) 1999, 2000, 2001 James A. Starkey
 *  All Rights Reserved.
 */

// Lock.cpp: implementation of the Lock class.
//
//////////////////////////////////////////////////////////////////////

#include "Lock.h"

namespace IscDbcLibrary {

using namespace classMutex;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Lock::Lock(Mutex *mtx)
{
	locked = false;
	mutex = mtx;
}

Lock::~Lock()
{
	if (locked)
		mutex->release();
}

void Lock::lock()
{
	if (!locked)
		{
		mutex->lock();
		locked = true;
		}
}

void Lock::release()
{
	if (locked)
		{
		mutex->release();
		locked = false;
		}
}

}; // end namespace IscDbcLibrary
