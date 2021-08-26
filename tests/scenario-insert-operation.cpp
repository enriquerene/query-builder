SCENARIO("Building a query for inserting data into specific table named my_table inside database.", "[query-builder]") {
    DBTools::QueryBuilder qb;
    std::string tableNameForTests = "my_table";

    SECTION("Insert firstName, lastName and email data into respective columns of table.") {
        std::map<std::string, std::string> data = {
            {"firstName", "'First'"},
            {"lastName", "'Last'"},
            {"email", "'first@last.com'"}
        };
        std::string queryString = qb.Insert(tableNameForTests, data).getQueryString();
        
        REQUIRE(queryString == "INSERT INTO " + tableNameForTests + " (email, firstName, lastName) VALUES ('first@last.com', 'First', 'Last')");
    }

    SECTION("Insert product_title and product_quantity data into respective columns of table.") {
        std::map<std::string, std::string> data = {
            {"product_title", "'my product'"},
            {"product_quantity", "10"}
        };
        std::string queryString = qb.Insert(tableNameForTests, data).getQueryString();
        
        REQUIRE(queryString == "INSERT INTO " + tableNameForTests + " (product_quantity, product_title) VALUES (10, 'my product')");
    }
}
