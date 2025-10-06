#ifndef CARDPARSER_H
#define CARDPARSER_H


#endif  // CARDPARSER_H

#include <QDebug>
#include <QString>
#include <QObject>

class CardParser : public QObject {
    Q_OBJECT

    //Q_PROPERTY(QString cardInput READ cardInput WRITE setCardInput NOTIFY cardInputChanged)

public:
    explicit CardParser(QObject *parent = nullptr);
    ~CardParser();

    //QString cardInput() const;

    Q_INVOKABLE void setCardInput(QString newCardInput);
    Q_INVOKABLE void saveTextToFile(const QString &text);

    QString cardInputParse(QString cardData);

    QString parse(QString data);

signals:
    //QString cardInput();

    void cardInputChanged();

public slots:
    void cardInputReceived(const QString &message);

private:
    QString cardData;
};
