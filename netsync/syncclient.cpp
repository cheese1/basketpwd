#include "syncclient.h"

SyncClient::SyncClient(QObject *parent) :
    QObject(parent)
{
    _addr           = QHostAddress::Null;
    _port           = 35114;
    _clientID       = QString();
    _clientPosition = QDateTime::currentDateTime();
}
SyncClient::SyncClient(const QHostAddress &addr, quint16 port, QString clientID, const QDateTime &clientPos, QObject *parent) :
    QObject(parent)
{
    setAddress(addr);
    setPort(port);
    setClientID(clientID);
    setClientPosition(clientPos);
}

SyncClient::SyncClient(const SyncClient &copy)
    : QObject(copy.parent())
{
    setAddress(copy.address());
    setPort(copy.port());
    setClientID(copy.clientID());
    setClientPosition(copy.clientPosition());
    setParent(copy.parent());
}

// Modifiers
void SyncClient::setAddress(QString sAddr)
{
    _addr.setAddress(sAddr);
}
void SyncClient::setAddress(const QHostAddress &addr)
{
    _addr = addr;
}
QHostAddress SyncClient::address() const
{
    return _addr;
}

void SyncClient::setPort(quint16 port)
{
    _port = port;
}
quint16 SyncClient::port() const
{
    return _port;
}

void SyncClient::setClientID(QString id)
{
    _clientID = id;
}
QString SyncClient::clientID() const
{
    return _clientID;
}

void SyncClient::setClientPosition(const QDateTime &dt)
{
    _clientPosition = dt;
}
QDateTime SyncClient::clientPosition() const
{
    return _clientPosition;
}

bool SyncClient::equal(const SyncClient &i) const
{
    bool result = true;

    result &= ( i.address() == address() );
    result &= ( i.port() == port() );
    result &= ( i.clientID() == clientID() );
    result &= ( i.clientPosition() == clientPosition() );

    return result;
}

bool SyncClient::operator ==(const SyncClient &i) const
{
    return equal(i);
}

SyncClient &SyncClient::operator =(const SyncClient &t)
{
    if ( equal(t) )
        return *this;

    setAddress(t.address());
    setPort(t.port());
    setClientID(t.clientID());
    setClientPosition(t.clientPosition());

    return *this;
}
