#include "./data-manipulation-language.h"

QueryBuilder::DataManipulationLanguage::DataManipulationLanguage() {}

std::string QueryBuilder::DataManipulationLanguage::getQueryString() {
    std::string queryString = this->_queryMap["operation"];
    if (this->_queryMap["condition"] != "") {
        queryString += " ";
        queryString += this->_queryMap["condition"];
    }
    if (this->_queryMap["order"] != "") {
        queryString += " ";
        queryString += this->_queryMap["order"];
    }
    if (this->_queryMap["limit"] != "") {
        queryString += " ";
        queryString += this->_queryMap["limit"];
    }
    if (this->_queryMap["offset"] != "") {
        queryString += " ";
        queryString += this->_queryMap["offset"];
    }

    return queryString;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Select(std::string tableName, std::string fields) {
    std::string queryPiece = "SELECT " + fields + " FROM " + tableName;
    this->_queryMap["operation"] = queryPiece;

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Where(std::map<std::string, std::string> fieldValueMap, std::string joinner) {
    std::string queryPiece = "WHERE ";
    std::string pairs[fieldValueMap.size()];

    int counter = 0;
    for (std::map<std::string, std::string>::iterator it = fieldValueMap.begin(); it != fieldValueMap.end(); it++) {
        pairs[counter] = it->first;
        pairs[counter] += " = ";
        pairs[counter] += it->second;
        counter += 1;
    }
    joinner = " " + joinner + " ";
    queryPiece += QueryBuilder::Utils::joinStringArray(fieldValueMap.size(), pairs, joinner);
    this->_queryMap["condition"] = queryPiece;

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::OrderBy(std::map<std::string, std::string> fieldAscOrDescMap) {
    std::string queryPiece = "ORDER BY ";
    std::string pairs[fieldAscOrDescMap.size()];

    int counter = 0;
    for (std::map<std::string, std::string>::iterator it = fieldAscOrDescMap.begin(); it != fieldAscOrDescMap.end(); it++) {
        pairs[counter] = it->first;
        pairs[counter] += " = ";
        pairs[counter] += it->second;
        counter += 1;
    }
    queryPiece += QueryBuilder::Utils::joinStringArray(fieldAscOrDescMap.size(), pairs, ", ");
    this->_queryMap["order"] = queryPiece;

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::OrderBy(std::string fieldName) {
    std::string queryPiece = "ORDER BY " + fieldName;
    this->_queryMap["order"] = queryPiece;

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Limit(int limit) {
    this->_queryMap["limit"] = "LIMIT " + std::to_string(limit);

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Offset(int offset) {
    this->_queryMap["offset"] = "OFFSET " + std::to_string(offset);

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Insert(std::string tableName, std::map<std::string, std::string> data) {
    std::string queryColumns = "";
    std::string queryValues = "";
    for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); it++) {
        queryColumns += it->first;
        queryValues += it->second;
        if (std::next(it) != data.end()) {
            queryColumns += ", ";
            queryValues += ", ";
        }
    }

    this->_queryMap["operation"] = "INSERT INTO " + tableName + " (" + queryColumns + ") VALUES (" + queryValues + ")";

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Update(std::string tableName, std::map<std::string, std::string> data) {
    std::string query = "UPDATE " + tableName + " SET ";
    for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); it++) {
        query += it->first;
        query += " = ";
        query += it->second;
        if (std::next(it) != data.end()) {
            query += ", ";
        }
    }

    this->_queryMap["operation"] = query;

    return *this;
}

QueryBuilder::DataManipulationLanguage QueryBuilder::DataManipulationLanguage::Delete(std::string tableName) {
    this->_queryMap["operation"] = "DELETE FROM " + tableName;

    return *this;
}

