SCENARIO("Building a query for reading from a specific table named my_table inside database.", "[data-manipulation-language]") {
    QueryBuilder::DataManipulationLanguage qb;
    std::string tableNameForTests = "my_table";

    SECTION("Fetching all fields from table.") {
        std::string queryString = qb.Select(tableNameForTests).getQueryString();
        
        REQUIRE(queryString == "SELECT * FROM " + tableNameForTests);
    }

    SECTION("Fetching only ID field from table.") {
        std::string queryString = qb.Select(tableNameForTests, "ID").getQueryString();
        
        REQUIRE(queryString == "SELECT ID FROM " + tableNameForTests);
    }

    SECTION("Fetching ID and name fields from table.") {
        std::string query = qb.Select(tableNameForTests, "ID, name").getQueryString();
        
        REQUIRE(query == "SELECT ID, name FROM " + tableNameForTests);
    }

    SECTION("Fetching ID and name fields from table where scope is user.") {
        std::map<std::string, std::string> fieldValueMap = {{"scope", "'user'"}};
        std::string query = qb.Select(tableNameForTests, "ID, name").Where(fieldValueMap).getQueryString();

        REQUIRE(query == "SELECT ID, name FROM " + tableNameForTests + " WHERE scope = 'user'");
    }

    SECTION("Fetching ID and name fields from table where scope is user and email is my@email.com.") {
        std::map<std::string, std::string> fieldValueMap = {
            {"scope", "'user'"},
            {"email", "'my@email.com'"}
        };
        std::string query = qb.Select(tableNameForTests, "ID, name").Where(fieldValueMap).getQueryString();

        REQUIRE(query == "SELECT ID, name FROM " + tableNameForTests + " WHERE email = 'my@email.com' AND scope = 'user'");
    }

    SECTION("Fetching ID and name fields from table where scope is user or email is my@email.com.") {
        std::map<std::string, std::string> fieldValueMap = {
            {"scope", "'user'"},
            {"email", "'my@email.com'"}
        };
        std::string query = qb.Select(tableNameForTests, "ID, name").Where(fieldValueMap, "OR").getQueryString();

        REQUIRE(query == "SELECT ID, name FROM " + tableNameForTests + " WHERE email = 'my@email.com' OR scope = 'user'");
    }

    SECTION("Fetching all fields from table where scope is user ordered by name.") {
        std::map<std::string, std::string> fieldValueMap = {
            {"scope", "'user'"}
        };
        std::string orderStr = "name";
        std::string query = qb.Select(tableNameForTests).Where(fieldValueMap).OrderBy(orderStr).getQueryString();

        REQUIRE(query == "SELECT * FROM " + tableNameForTests + " WHERE scope = 'user' ORDER BY name");
    }

    SECTION("Fetching all fields and limit up to 100 results.") {
        std::string query = qb.Select(tableNameForTests).Limit(100).getQueryString();

        REQUIRE(query == "SELECT * FROM " + tableNameForTests + " LIMIT 100");
    }

    SECTION("Fetching all fields, up to 100 results with 50 rows offset.") {
        std::string query = qb.Select(tableNameForTests).Limit(100).Offset(50).getQueryString();

        REQUIRE(query == "SELECT * FROM " + tableNameForTests + " LIMIT 100 OFFSET 50");
    }
}

