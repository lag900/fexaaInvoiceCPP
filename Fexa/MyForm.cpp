#include "MyForm.h"
//#include "Database.h"
//using namespace Fexa;
//
//
//MyForm::MyForm(void) {
//
//    InitializeComponent(); // Always first
//    instance = this;
//    resources = gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);
//
//    // تأكد من أن الأعمدة موجودة
//    if (!this->data_cat->Columns->Contains("edit")) {
//        this->data_cat->Columns->Add("edit", "Edit");
//    }
//    if (!this->data_cat->Columns->Contains("del")) {
//        this->data_cat->Columns->Add("del", "Delete");
//    }
//
//    // Set the initial image for table img row
//    int rowIndex = this->data_cat->Rows->Add();
//    //int rowIndex = this->dataClient->Rows->Add();
//
//    // Adding images to the "edit" and "del" columns
//    this->data_cat->Rows[rowIndex]->Cells["edit"]->Value =
//        (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit")));
//    this->data_cat->Rows[rowIndex]->Cells["del"]->Value =
//        (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"del")));
//    this->dataClient->Rows[rowIndex]->Cells["editClient"]->Value =
//        (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit")));
//    this->dataClient->Rows[rowIndex]->Cells["delClient"]->Value =
//        (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"del")));
//    // data base  Store Table Category
//SqlConnection^ conn = Database::GetCon();
//try {
//    conn->Open();
//
//    SqlCommand^ cmd = gcnew SqlCommand("SELECT ID, category_name FROM categories", conn);
//    SqlDataReader^ reader = cmd->ExecuteReader();
//
//    while (reader->Read()) {
//        int rowIndex = this->data_cat->Rows->Add();
//
//        this->data_cat->Rows[rowIndex]->Cells["ID_Cat"]->Value = reader["id"];
//        this->data_cat->Rows[rowIndex]->Cells["name_Cat"]->Value = reader["category_name"];
//        this->data_cat->Rows[rowIndex]->Cells["edit"]->Value =
//            (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit")));
//        this->data_cat->Rows[rowIndex]->Cells["del"]->Value =
//            (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"del")));
//    }
//
//    reader->Close();
//    conn->Close();
//}
//catch (Exception^ ex) {
//    MessageBox::Show("Database Error: " + ex->Message);
//}

//    TableClient();
//};
//// data base  Store Table CLients
//MyForm::TableClient()
//{
//    SqlConnection^ conn = Database::GetCon();
//    String^ query = "SELECT ID, name, phone, email, city, location FROM clients";
//    try
//    {
//        conn->Open();
//        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
//        SqlDataReader^ reader = cmd->ExecuteReader();
//        while (reader->Read()) {
//            int rowIndex = this->dataClient->Rows->Add();
//            this->dataClient->Rows[rowIndex]->Cells["dataGridViewTextBoxColumn1"]->Value = reader["ID"];
//            this->dataClient->Rows[rowIndex]->Cells["NameClient"]->Value = reader["name"];
//            this->dataClient->Rows[rowIndex]->Cells["PhoneClient"]->Value = reader["phone"];
//            this->dataClient->Rows[rowIndex]->Cells["EmailClient"]->Value = reader["email"];
//            this->dataClient->Rows[rowIndex]->Cells["CityClient"]->Value = reader["city"];
//            this->dataClient->Rows[rowIndex]->Cells["LoctionClient"]->Value = reader["location"];
//            this->dataClient->Rows[rowIndex]->Cells["editClient"]->Value =
//                (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit")));
//            this->dataClient->Rows[rowIndex]->Cells["delClient"]->Value =
//                (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"del")));
//        }
//        reader->Close();
//        conn->Close();
//
//    }
//    catch (Exception^ ex)
//    {
//
//    }
//}