namespace QueryBuilder {
class Utils {
    public:
    /** 
     * Join a string array entries into a unique string.
     * 
     * @param the array of strings
     * @param string placed between each entry.
     * @return the resultant string.
     */
    static std::string joinStringArray(size_t arrSize, std::string const *strArr, std::string strJoinner = "");
};
} // namespace QueryBuilder
