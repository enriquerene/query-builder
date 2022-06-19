namespace QueryBuilder {
class DataManipulationLanguage {
    private:
    std::map<std::string, std::string> _queryMap = {
        {"operation", ""},
        {"condition", ""},
        {"order", ""},
        {"limit", ""},
        {"offset", ""}
    };

    public:
    /**
     * Trivial constructor
     */
    DataManipulationLanguage();

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
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Select(std::string tableName, std::string fields = "*");

    /** 
     * Get where statement SQL result.
     * 
     * @param map of fields as key and expected value as values
     * @param joinner of statement pieces.
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Where(std::map<std::string, std::string> fieldValueMap, std::string joinner = "AND");

    /** 
     * Get order by statement SQL result.
     * 
     * @param map of field as key and ASC or DESC as value
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage OrderBy(std::map<std::string, std::string> fieldAscOrDescMap);

    /** 
     * Get order by statement SQL result.
     * 
     * @param name of the field
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage OrderBy(std::string fieldName);

    /** 
     * Get limit statement SQL result.
     * 
     * @param the number of results limited at
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Limit(int limit);

    /** 
     * Get offset statement SQL result.
     * 
     * @param the number of rows to be skipped
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Offset(int offset);

    /** 
     * Get insert statement SQL result.
     * 
     * @param table name
     * @param key value pair map of fields to be inserted
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Insert(std::string tableName, std::map<std::string, std::string> data);

    /** 
     * Get update statement SQL result.
     * 
     * @param table name
     * @param key value pair map of fields to be updated
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Update(std::string tableName, std::map<std::string, std::string> fieldValueMap);

    /** 
     * Get delete statement SQL result.
     * 
     * @param table name
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Delete(std::string tableName);

    /** 
     * Get create table statement SQL result.
     * 
     * @param table name
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage CreateTable(std::string tableName);

    /** 
     * Add a column with primary key index in create table statement SQL result. This column will be integer AUTO_INCREMENT also.
     * 
     * @param field name
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage WithPrimaryField(std::string fieldName);

    /** 
     * Add a column with varchar type in create table statement SQL result. It's nullable by default.
     * 
     * @param field name
     * @param chars max size
     * @param if field must be NOT NULL label column
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage WithVarcharField(std::string fieldName, int size, bool isNotNull = false);

    /** 
     * Add a column with char type in create table statement SQL result. It's nullable by default.
     * 
     * @param field name
     * @param char size
     * @param if field must be NOT NULL label column
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage WithCharField(std::string fieldName, int size, bool isNotNull = false);

    /** 
     * Add a column with char type in create table statement SQL result. It's nullable by default.
     * 
     * @param field name
     * @param int size
     * @param if field must be NOT NULL label column
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage WithIntField(std::string fieldName, int size, bool isNotNull = false);

    /** 
     * Add a column with TIMESTAMP type in create table statement SQL result. It's nullable by default.
     * 
     * @param true it default value must be CURRENT_TIMESTAMP
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage WithTimestampField(bool isCurrentTimestamp = false);

    /** 
     * Add ON UPDATE constraint to the last field appended to the query in create table statement SQL.
     * 
     * @param the value to update the column when table is updated
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage OnUpdate(std::string value);

    /** 
     * Add a UNIQUE constraint to the last field appended to the query in create table statement SQL.
     * 
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Unique();

    /** 
     * Add a DEFAULT constraint to the last field appended to the query in create table statement SQL.
     * 
     * @param default value
     * @return A modified DataManipulationLanguage instance
     */
    DataManipulationLanguage Default(std::string defaultValue);
};
} // namespace QueryBuilder
