#include "CardParser.h"
#include <QDebug>
#include <QTextStream>
#include <QStandardPaths>
#include <QFile>

CardParser::CardParser(QObject *parent) : QObject(parent) {

}

CardParser::~CardParser() {

}

QString CardParser::parse(QString data) {
    QString parsedData;

    return parsedData;
}

void CardParser::setCardInput(QString data) {

}

void CardParser::saveTextToFile(const QString &data) {
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/output.txt";

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << data;
        file.close();
        qDebug() << "File saved to: " << filePath;
    } else {
        qWarning() << "Failed to save the file";
    }
}

QString CardParser::cardInputParse(QString cardInput) {
    return "";
}

void CardParser::cardInputReceived(const QString &message) {
    qDebug() << "Card Input Received: " << message;

    std::string card = message.toStdString();

    size_t track1_start = card.find("%B");
    size_t track2_start = card.find(";");
    size_t track3_start = card.find("+");

    if (track1_start != std::string::npos) {
        size_t end = card.find("?", track1_start);
        std::string track1 = card.substr(track1_start, end - track1_start + 1);
        qDebug() << "Track 1: " << track1;
    }

    if (track2_start != std::string::npos) {
        size_t end = card.find("?", track2_start);
        std::string track2 = card.substr(track2_start, end - track2_start + 1);
        qDebug() << "Track 2: " << track2;
    }

    if (track3_start != std::string::npos) {
        size_t end = card.find("?", track3_start);
        std::string track3 = card.substr(track3_start, end - track3_start + 1);
        qDebug() << "Track 3: " << track3;
    }

    //cardInputParse(message);
}

/*
std::string card;
std::cout << "Please swipe the card" << "\n";

std::getline(std::cin, card);

std::cout << "Raw Card Data: " << card << std::endl;

size_t track1_start = card.find("%B");
size_t track2_start = card.find(";");
size_t track3_start = card.find("+");

if (track1_start != std::string::npos) {
    size_t end = card.find("?", track1_start);
    std::string track1 = card.substr(track1_start, end - track1_start + 1);
    std::cout << "Track 1: " << track1 << std::endl;
}

if (track2_start != std::string::npos) {
    size_t end = card.find("?", track2_start);
    std::string track2 = card.substr(track2_start, end - track2_start + 1);
    std::cout << "Track 2: " << track2 << std::endl;
}

if (track3_start != std::string::npos) {
    size_t end = card.find("?", track3_start);
    std::string track3 = card.substr(track3_start, end - track3_start + 1);
    std::cout << "Track 3: " << track3 << std::endl;
}

return 0;
*/
