SCENARIO("Building a query for update data of a specific table named my_table inside database.", "[data-manipulation-language]") {
    QueryBuilder::DataManipulationLanguage qb;
    std::string tableNameForTests = "my_table";

    SECTION("Update product_title and product_quantity data of a table.") {
        std::map<std::string, std::string> data = {
            {"product_title", "'my product'"},
            {"product_quantity", "10"}
        };
        std::string queryString = qb.Update(tableNameForTests, data).getQueryString();
        
        REQUIRE(queryString == "UPDATE " + tableNameForTests + " SET product_quantity = 10, product_title = 'my product'");
    }

    SECTION("Update product_title and product_quantity data of a table where type is 'simple'.") {
        std::map<std::string, std::string> data = {
            {"product_title", "'my product'"},
            {"product_quantity", "10"}
        };
        std::string queryString = qb.Update(tableNameForTests, data).Where({{"type", "'simple'"}}).getQueryString();
        
        REQUIRE(queryString == "UPDATE " + tableNameForTests + " SET product_quantity = 10, product_title = 'my product' WHERE type = 'simple'");
    }
}
