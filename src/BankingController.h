#pragma once
#include <QObject>
#include <QString>

class BankingController final : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double balance READ balance NOTIFY balanceChanged)
    Q_PROPERTY(bool loggedIn READ loggedIn NOTIFY loggedInChanged)
    Q_PROPERTY(QString message READ message NOTIFY messageChanged)
public:
    explicit BankingController(QObject *parent = nullptr);
    double balance() const;
    bool loggedIn() const;
    QString message() const;

    Q_INVOKABLE bool login(const QString &username, const QString &password);
    Q_INVOKABLE void logout();
    Q_INVOKABLE bool deposit(double amount);
    Q_INVOKABLE bool withdraw(double amount);

signals:
    void balanceChanged();
    void loggedInChanged();
    void messageChanged();

private:
    void setMessage(const QString &message);
    qint64 m_balanceCents = 250000;
    bool m_loggedIn = false;
    QString m_message;
};
