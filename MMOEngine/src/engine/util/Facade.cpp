/*
 *	engine/util/Facade.cpp generated by engine3 IDL compiler 0.60
 */

#include "Facade.h"

/*
 *	FacadeStub
 */

enum {RPC_INITIALIZESESSION__ = 6,RPC_CANCELSESSION__,RPC_CLEARSESSION__};

Facade::Facade() : ManagedObject(DummyConstructorParameter::instance()) {
	FacadeImplementation* _implementation = new FacadeImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Facade");
}

Facade::Facade(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("Facade");
}

Facade::~Facade() {
}



int Facade::initializeSession() {
	FacadeImplementation* _implementation = static_cast<FacadeImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZESESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->initializeSession();
}

int Facade::cancelSession() {
	FacadeImplementation* _implementation = static_cast<FacadeImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->cancelSession();
}

int Facade::clearSession() {
	FacadeImplementation* _implementation = static_cast<FacadeImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->clearSession();
}

DistributedObjectServant* Facade::_getImplementation() {

	_updated = true;
	return _impl;
}

void Facade::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	FacadeImplementation
 */

FacadeImplementation::FacadeImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


FacadeImplementation::~FacadeImplementation() {
}


void FacadeImplementation::finalize() {
}

void FacadeImplementation::_initializeImplementation() {
	_setClassHelper(FacadeHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void FacadeImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Facade*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FacadeImplementation::_getStub() {
	return _this;
}

FacadeImplementation::operator const Facade*() {
	return _this;
}

void FacadeImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void FacadeImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void FacadeImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void FacadeImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void FacadeImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void FacadeImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void FacadeImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void FacadeImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Facade");

}

void FacadeImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(FacadeImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FacadeImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void FacadeImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FacadeImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FacadeImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

FacadeImplementation::FacadeImplementation() {
	_initializeImplementation();
	// engine/util/Facade.idl():  		Logger.setLoggingName("Facade");
	Logger::setLoggingName("Facade");
}

int FacadeImplementation::initializeSession() {
	// engine/util/Facade.idl():  		return 0;
	return 0;
}

int FacadeImplementation::cancelSession() {
	// engine/util/Facade.idl():  		return 0;
	return 0;
}

int FacadeImplementation::clearSession() {
	// engine/util/Facade.idl():  		return 0;
	return 0;
}

/*
 *	FacadeAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


FacadeAdapter::FacadeAdapter(Facade* obj) : ManagedObjectAdapter(obj) {
}

void FacadeAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZESESSION__:
		resp->insertSignedInt(initializeSession());
		break;
	case RPC_CANCELSESSION__:
		resp->insertSignedInt(cancelSession());
		break;
	case RPC_CLEARSESSION__:
		resp->insertSignedInt(clearSession());
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int FacadeAdapter::initializeSession() {
	return (static_cast<Facade*>(stub))->initializeSession();
}

int FacadeAdapter::cancelSession() {
	return (static_cast<Facade*>(stub))->cancelSession();
}

int FacadeAdapter::clearSession() {
	return (static_cast<Facade*>(stub))->clearSession();
}

/*
 *	FacadeHelper
 */

FacadeHelper* FacadeHelper::staticInitializer = FacadeHelper::instance();

FacadeHelper::FacadeHelper() {
	className = "Facade";

	Core::getObjectBroker()->registerClass(className, this);
}

void FacadeHelper::finalizeHelper() {
	FacadeHelper::finalize();
}

DistributedObject* FacadeHelper::instantiateObject() {
	return new Facade(DummyConstructorParameter::instance());
}

DistributedObjectServant* FacadeHelper::instantiateServant() {
	return new FacadeImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FacadeHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FacadeAdapter(static_cast<Facade*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

