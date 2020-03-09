// Copyright (c) 2011-2013 The Bitcoin developers
// Copyright (c) 2017 The PIVX developers
// Copyright (c) 2017-2018 The HUZU developers
// Copyright (c) 2018-2019 The ZIJA developers
// Copyright (c) 2019 The CGEN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_OVERVIEWPAGE_H
#define BITCOIN_QT_OVERVIEWPAGE_H

#include "amount.h"

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QStandardItemModel>

class ClientModel;
class TransactionFilterProxy;
class TxViewDelegate;
class WalletModel;

namespace Ui
{
class OverviewPage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget* parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel* clientModel);
    void setWalletModel(WalletModel* walletModel);
    void showOutOfSyncWarning(bool fShow);

public slots:
    void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, 
                    const CAmount& zerocoinBalance, const CAmount& unconfirmedZerocoinBalance, const CAmount& immatureZerocoinBalance,
                    const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);

signals:
    void transactionClicked(const QModelIndex& index);

private:
    QTimer* timer;
    Ui::OverviewPage* ui;
    ClientModel* clientModel;
    WalletModel* walletModel;
    CAmount currentBalance;
    CAmount currentUnconfirmedBalance;
    CAmount currentImmatureBalance;
    CAmount currentZerocoinBalance;
    CAmount currentUnconfirmedZerocoinBalance;
    CAmount currentimmatureZerocoinBalance;
    CAmount currentWatchOnlyBalance;
    CAmount currentWatchUnconfBalance;
    CAmount currentWatchImmatureBalance;
    int nDisplayUnit;
    void getPercentage(CAmount nTotalBalance, CAmount nZerocoinBalance, QString& sCGENPercentage, QString& szCGENPercentage);
    QNetworkAccessManager *networkManager;
    TxViewDelegate* txdelegate;
    TransactionFilterProxy* filter;

private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex& index);
    void updateAlerts(const QString& warnings);
    void updateWatchOnlyLabels(bool showWatchOnly);
	void on_pushButton_Website_clicked();
    void on_pushButton_Explorer_clicked();
    void on_pushButton_Cmc_clicked();
    void on_pushButton_Crex24_clicked();
    void on_pushButton_Telegram_clicked();
    void on_pushButton_Bitcointalk_clicked();
    void on_pushButton_Twitter_clicked();
	    void on_pushButton_Discord_clicked();
	    void onResult(QNetworkReply *reply);

};

#endif // BITCOIN_QT_OVERVIEWPAGE_H
