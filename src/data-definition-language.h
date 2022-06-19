namespace QueryBuilder {
class DataDefinitionLanguage {
    private:
    std::map<std::string, std::string> _creationTableQueryMap = {
        {"operation", ""},
        {"rules", ""}
    };

    public:
    /**
     * Trivial constructor
     */
    DataDefinitionLanguage();

    /**
     * Get the build query as string
     *
     * @return A SQL string for apply against database
     */
    std::string getQueryString();

    /** 
     * Get select statement SQL result with table name and required fields as optional parameter. If no fields are said as required, all fields will come up.
     * 
     * @param specific table name
     * @param fields to be the output as comma separated values in list
     * @return A modified DataDefinitionLanguage instance
     */
    DataDefinitionLanguage CreateTable(std::string tableName, std::string fields = "*");
};
} // namespace QueryBuilder

#endif
