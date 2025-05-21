#pragma once
using namespace System;
using namespace System::Data::SqlClient;

#pragma once

//SqlConnection^ con = Database::GetCon();

public ref class Database
{
public:
    static SqlConnection^ GetCon()
    {
        String^ connectionString = "Data Source=DESKTOP-6E83744;Initial Catalog=store;Integrated Security=True";
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        return conn;
    }
};
