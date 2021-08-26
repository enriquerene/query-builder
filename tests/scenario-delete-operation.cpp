SCENARIO("Building a query for delete data from specific table named my_table inside database.", "[query-builder]") {
    DBTools::QueryBuilder qb;
    std::string tableNameForTests = "my_table";

    SECTION("Delete all rows of table.") {
        std::string queryString = qb.Delete(tableNameForTests).getQueryString();
        REQUIRE(queryString == "DELETE FROM " + tableNameForTests);
    }

    SECTION("Delete rows of table where type is 'simple'.") {
        std::string queryString = qb.Delete(tableNameForTests).Where({{"type", "'simple'"}}).getQueryString();
        REQUIRE(queryString == "DELETE FROM " + tableNameForTests + " WHERE type = 'simple'");
    }
}
