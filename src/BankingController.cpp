#include "BankingController.h"
#include <QtGlobal>
#include <cmath>

BankingController::BankingController(QObject *parent) : QObject(parent) {}
double BankingController::balance() const { return m_balanceCents / 100.0; }
bool BankingController::loggedIn() const { return m_loggedIn; }
QString BankingController::message() const { return m_message; }

void BankingController::setMessage(const QString &message)
{
    m_message = message;
    emit messageChanged();
}

bool BankingController::login(const QString &username, const QString &password)
{
    // Demo-only credentials; not production authentication.
    if (username == "demo" && password == "demo123") {
        m_loggedIn = true;
        emit loggedInChanged();
        setMessage("Welcome back.");
        return true;
    }
    setMessage("Invalid username or password.");
    return false;
}

void BankingController::logout()
{
    m_loggedIn = false;
    emit loggedInChanged();
    setMessage("You have signed out.");
}

bool BankingController::deposit(double amount)
{
    if (!m_loggedIn) { setMessage("Please sign in first."); return false; }
    if (!std::isfinite(amount) || amount <= 0.0 || amount > 1000000.0) {
        setMessage("Enter a valid amount."); return false;
    }
    const qint64 cents = qRound64(amount * 100.0);
    if (cents <= 0) { setMessage("Enter a valid amount."); return false; }
    m_balanceCents += cents;
    emit balanceChanged();
    setMessage(QString("Deposit of $%1 completed.").arg(cents / 100.0, 0, 'f', 2));
    return true;
}

bool BankingController::withdraw(double amount)
{
    if (!m_loggedIn) { setMessage("Please sign in first."); return false; }
    if (!std::isfinite(amount) || amount <= 0.0 || amount > 1000000.0) {
        setMessage("Enter a valid amount."); return false;
    }
    const qint64 cents = qRound64(amount * 100.0);
    if (cents <= 0) { setMessage("Enter a valid amount."); return false; }
    if (cents > m_balanceCents) { setMessage("Insufficient funds."); return false; }
    m_balanceCents -= cents;
    emit balanceChanged();
    setMessage(QString("Withdrawal of $%1 completed.").arg(cents / 100.0, 0, 'f', 2));
    return true;
}
