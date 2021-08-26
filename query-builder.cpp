#include "query-builder.h"

std::string DBTools::QueryBuilder::joinStringArray(size_t arrSize, std::string const *strArr, std::string strJoinner) {
    std::string str = "";
    for (size_t i = 0; i < arrSize; i++) {
        str += strArr[i];
        if (i < arrSize - 1) {
            str += strJoinner;
        }
    }
    return str;
}

DBTools::QueryBuilder::QueryBuilder() {}

std::string DBTools::QueryBuilder::getQueryString() {
    std::string queryString = this->_commonQueryMap["operation"];
    if (this->_commonQueryMap["condition"] != "") {
        queryString += " ";
        queryString += this->_commonQueryMap["condition"];
    }
    if (this->_commonQueryMap["order"] != "") {
        queryString += " ";
        queryString += this->_commonQueryMap["order"];
    }
    if (this->_commonQueryMap["limit"] != "") {
        queryString += " ";
        queryString += this->_commonQueryMap["limit"];
    }
    if (this->_commonQueryMap["offset"] != "") {
        queryString += " ";
        queryString += this->_commonQueryMap["offset"];
    }

    return queryString;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Select(std::string tableName, std::string fields) {
    std::string queryPiece = "SELECT " + fields + " FROM " + tableName;
    this->_commonQueryMap["operation"] = queryPiece;

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Where(std::map<std::string, std::string> fieldValueMap, std::string joinner) {
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
    queryPiece += DBTools::QueryBuilder::joinStringArray(fieldValueMap.size(), pairs, joinner);
    this->_commonQueryMap["condition"] = queryPiece;

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::OrderBy(std::map<std::string, std::string> fieldAscOrDescMap) {
    std::string queryPiece = "ORDER BY ";
    std::string pairs[fieldAscOrDescMap.size()];

    int counter = 0;
    for (std::map<std::string, std::string>::iterator it = fieldAscOrDescMap.begin(); it != fieldAscOrDescMap.end(); it++) {
        pairs[counter] = it->first;
        pairs[counter] += " = ";
        pairs[counter] += it->second;
        counter += 1;
    }
    queryPiece += DBTools::QueryBuilder::joinStringArray(fieldAscOrDescMap.size(), pairs, ", ");
    this->_commonQueryMap["order"] = queryPiece;

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::OrderBy(std::string fieldName) {
    std::string queryPiece = "ORDER BY " + fieldName;
    this->_commonQueryMap["order"] = queryPiece;

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Limit(int limit) {
    this->_commonQueryMap["limit"] = "LIMIT " + std::to_string(limit);

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Offset(int offset) {
    this->_commonQueryMap["offset"] = "OFFSET " + std::to_string(offset);

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Insert(std::string tableName, std::map<std::string, std::string> data) {
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

    this->_commonQueryMap["operation"] = "INSERT INTO " + tableName + " (" + queryColumns + ") VALUES (" + queryValues + ")";

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Update(std::string tableName, std::map<std::string, std::string> data) {
    std::string query = "UPDATE " + tableName;
    for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); it++) {
        query += " SET ";
        query += it->first;
        query += " = ";
        query += it->second;
        if (std::next(it) != data.end()) {
            query += ",";
        }
    }

    this->_commonQueryMap["operation"] = query;

    return *this;
}

DBTools::QueryBuilder DBTools::QueryBuilder::Delete(std::string tableName) {
    this->_commonQueryMap["operation"] = "DELETE FROM " + tableName;

    return *this;
}

