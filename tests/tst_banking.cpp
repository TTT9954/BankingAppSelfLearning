#include <QtTest>
#include "../src/BankingController.h"

class BankingTests : public QObject
{
    Q_OBJECT
private slots:
    void loginRequiresCorrectCredentials()
    {
        BankingController controller;
        QVERIFY(!controller.login("wrong", "wrong"));
        QVERIFY(!controller.loggedIn());
        QVERIFY(controller.login("demo", "demo123"));
        QVERIFY(controller.loggedIn());
    }

    void depositAndWithdrawUpdateBalance()
    {
        BankingController controller;
        QVERIFY(controller.login("demo", "demo123"));
        const qint64 startingCents = qRound64(controller.balance() * 100.0);
        QVERIFY(controller.deposit(25.50));
        QCOMPARE(qRound64(controller.balance() * 100.0), startingCents + 2550);
        QVERIFY(controller.withdraw(10.25));
        QCOMPARE(qRound64(controller.balance() * 100.0), startingCents + 1525);
    }

    void invalidOperationsAreRejected()
    {
        BankingController controller;
        QVERIFY(!controller.deposit(10.0)); // signed out
        QVERIFY(controller.login("demo", "demo123"));
        const qint64 start = qRound64(controller.balance() * 100.0);
        QVERIFY(!controller.deposit(-1.0));
        QVERIFY(!controller.withdraw(0.0));
        QVERIFY(!controller.withdraw(100000.0));
        QCOMPARE(qRound64(controller.balance() * 100.0), start);
    }
};

QTEST_GUILESS_MAIN(BankingTests)
#include "tst_banking.moc"
