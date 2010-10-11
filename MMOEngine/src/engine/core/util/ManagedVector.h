/*
 *	engine/core/util/ManagedVector.h generated by engine3 IDL compiler 0.61
 */

#ifndef MANAGEDVECTOR_H_
#define MANAGEDVECTOR_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace engine {
namespace core {
namespace util {

class ManagedVector : public DistributedObjectStub {
public:
	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ManagedVector(DummyConstructorParameter* param);

	virtual ~ManagedVector();

	friend class ManagedVectorHelper;
};

class ManagedVectorImplementation : public DistributedObjectServant {

public:
	ManagedVectorImplementation();
	ManagedVectorImplementation(DummyConstructorParameter* param);

	ManagedVector* _this;

	operator const ManagedVector*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~ManagedVectorImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class ManagedVector;
};

class ManagedVectorAdapter : public DistributedObjectAdapter {
public:
	ManagedVectorAdapter(ManagedVectorImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class ManagedVectorHelper : public DistributedObjectClassHelper, public Singleton<ManagedVectorHelper> {
	static ManagedVectorHelper* staticInitializer;

public:
	ManagedVectorHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ManagedVectorHelper>;
};

} // namespace util
} // namespace core
} // namespace engine

using namespace engine::core::util;

#endif /*MANAGEDVECTOR_H_*/
