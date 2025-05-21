#pragma once
#include "Database.h"
using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;

ref class ClientHelper
{
public:
    static void TableClient(DataGridView^ grid, System::ComponentModel::ComponentResourceManager^ resources)
    {
        SqlConnection^ conn = Database::GetCon();
        String^ query = "SELECT ID, name, phone, email, city, location FROM clients";

        try {
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            SqlDataReader^ reader = cmd->ExecuteReader();

            grid->Rows->Clear(); // تأكد إنك تمسح القديم قبل التحديث

            while (reader->Read()) {
                int rowIndex = grid->Rows->Add();
                grid->Rows[rowIndex]->Cells["dataGridViewTextBoxColumn1"]->Value = reader["ID"];
                grid->Rows[rowIndex]->Cells["NameClient"]->Value = reader["name"];
                grid->Rows[rowIndex]->Cells["PhoneClient"]->Value = reader["phone"];
                grid->Rows[rowIndex]->Cells["EmailClient"]->Value = reader["email"];
                grid->Rows[rowIndex]->Cells["CityClient"]->Value = reader["city"];
                grid->Rows[rowIndex]->Cells["LoctionClient"]->Value = reader["location"];
                grid->Rows[rowIndex]->Cells["editClient"]->Value =
                    (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit")));
                grid->Rows[rowIndex]->Cells["delClient"]->Value =
                    (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"del")));
            }

            reader->Close();
            conn->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }
};
