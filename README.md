# Query Builder
Query Builder makes your life easier building SQL queries with pretty intuitive API.

## Summary
- Overview
- Installation
- Usage
- Examples
- API reference
- Roadmap

## Overview
Query Builder provides an easy to use API for creating SQL queries. It gets inspiration from libraries like Eloquent in PHP programming.

## Installation
You only need to add the `dist/query-builder.h` into your project. It's important to be the header file from `dist` directory.
```shell
curl https://github.com/..../dist/query-builder.h -o your-project/libs/query-builder.h
```

## Usage
Following the installation example path `your-project/libs/query-builder.h`, you can include Query Builder into your project and add the `-Ilibs` flag to compiler. Here assumes you are compiling into `your-project` directory:
```C++
#include "libs/query-builder.h"
```

Optionally, it's possible compile the Query Builder library once and link to your project as needed:
```shell
cd /your-project/libs
g++ -c query-builder.h
```


## Examples
Building query for reading from a specific table named my_table inside database.

Fetching all fields from table.:
```C++
DBTools::QueryBuilder qb;
std::string queryString = qb.Select("my_table").getQueryString();
// "SELECT * FROM my_table" 
```

Fetching only ID field from table.
```C++
DBTools::QueryBuilder qb;
std::string queryString = qb.Select("my_table", "ID").getQueryString();
// "SELECT ID FROM my_table" 
```

```C++
DBTools::QueryBuilder qb;
Fetching ID and name fields from table.
std::string query = qb.Select("my_table", "ID, name").getQueryString();
// "SELECT ID, name FROM my_table"
```

Fetching ID and name fields from table where scope is user.
```C++
DBTools::QueryBuilder qb;
std::string query = qb.Select("my_table", "ID, name").Where({{"scope", "'user'"}}).getQueryString();
//  "SELECT ID, name FROM my_table WHERE scope = 'user'"
```

Fetching all fields and limit up to 100 results.
```C++
DBTools::QueryBuilder qb;
std::string query = qb.Select("my_table").Limit(100).getQueryString();
//  "SELECT * FROM my_table LIMIT 100"
```

Building a query for inserting data into specific table named my_table inside database.

Insert product_title and product_quantity data into respective columns of table.
```C++
DBTools::QueryBuilder qb;
std::string query = qb.Select("my_table").Limit(100).getQueryString();
std::map<std::string, std::string> data = {
    {"product_title", "'my product'"},
    {"product_quantity", "10"}
};
std::string queryString = qb.Insert("my_table", data).getQueryString();
// "INSERT INTO my_table (product_quantity, product_title) VALUES (10, 'my product')"
```
        
See API reference for complete usage.

## API reference
In development process.

## Roadmap
These are the next steps for future releases:
- Build API Reference
- Define the functions that create the database tables
