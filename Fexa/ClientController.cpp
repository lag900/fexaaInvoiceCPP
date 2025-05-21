// ClientController.cpp
#include "ClientController.h"
#include "Database.h"
#include "ProductCard.h"


void ClientController::LoadClients(DataGridView ^ dataGridView, Image ^ editImg, Image ^ delImg)
{   ///conn :كائن بيفتح الداتا بيز انا بمسية المفتاح 

    SqlConnection^ conn = Database::GetCon();
	/// لو واحد انت عطيته المفتاح هتقول اية اطلع جيب ليا شوية حاجات من الداتا بيز
	/// وانا هقولك اية الحاجات اللى عايزها من الداتا بيز
    String^ query = "SELECT ID, name, phone, email, city, location FROM clients";

    try
	{   /// بفتح الداتا 
        conn->Open();
		/// ده المسؤل عن انى اقول للداتا بيز اية اللى عايزة منة

        SqlCommand^ cmd = gcnew SqlCommand(query, conn);

		///انا محتاج حاجة تقرا الحاجات الي جبتها من الداتا بيز

        SqlDataReader^ reader = cmd->ExecuteReader();



         /// محمد واحمد 
		 /// جيت ضيفت حسام من غير ما امسح محمد واحمد
         /// اية الي هايحصل  الداتا هتكون عبارة عن  محمد احمد و محمد واحمد وحسام
         /// ده من غير المسح 
        dataGridView->Rows->Clear(); // امسح البيانات القديمة

        while (reader->Read()) {
			/// ضيف صف جديد في الداتا جريد فيو
            int rowIndex = dataGridView->Rows->Add();
            dataGridView->Rows[rowIndex]->Cells["dataGridViewTextBoxColumn1"]->Value = reader["ID"];
            dataGridView->Rows[rowIndex]->Cells["NameClient"]->Value = reader["name"];
            dataGridView->Rows[rowIndex]->Cells["PhoneClient"]->Value = reader["phone"];
            dataGridView->Rows[rowIndex]->Cells["EmailClient"]->Value = reader["email"];
            dataGridView->Rows[rowIndex]->Cells["CityClient"]->Value = reader["city"];
            dataGridView->Rows[rowIndex]->Cells["LoctionClient"]->Value = reader["location"];

        }

        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Database Error: " + ex->Message);
    }
}
void ClientController::LoadCat(DataGridView^ dcat, Image^ editcat, Image^ delcat)
{
    SqlConnection^ conn = Database::GetCon();
    String^ query = "SELECT ID, category_name FROM categories";

    try {

        conn->Open();
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        SqlDataReader^ reader = cmd->ExecuteReader();

        
        while (reader->Read()) {

            int rowIndex = dcat->Rows->Add();
			///dcat->Rows[rowIndex] هات رقم الصف الي احنا شغالين عليه 
			/// Cells["ID_Cat"]->Value = reader["ID"];  هات القيمة من الداتا بيز و حطها في

            dcat->Rows[rowIndex]->Cells["ID_Cat"]->Value = reader["ID"];
            dcat->Rows[rowIndex]->Cells["name_Cat"]->Value = reader["category_name"];
            dcat->Rows[rowIndex]->Cells["edit"]->Value = editcat;
            dcat->Rows[rowIndex]->Cells["del"]->Value = delcat;
        }

        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Database Error: " + ex->Message);
    }


}
void ClientController::LoadProducts(DataGridView^ dataGridView, Image^ editImg, Image^ delImg, String^ searchText)
{
    SqlConnection^ conn = Database::GetCon();
    String^ query = "SELECT ProductID, ProductName, Photo, BuyingPrice, Quantity, SellingPrice, DiscountedPrice, CategoryName FROM Product";

    if (!String::IsNullOrEmpty(searchText)) {
        query += " WHERE ProductName LIKE @search OR CategoryName LIKE @search";
    }

    try {
        conn->Open();
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        if (!String::IsNullOrEmpty(searchText)) {
            cmd->Parameters->AddWithValue("@search", "%" + searchText + "%");
        }

        SqlDataReader^ reader = cmd->ExecuteReader();
        dataGridView->Rows->Clear();
        while (reader->Read()) {
            int rowIndex = dataGridView->Rows->Add();
            dataGridView->Rows[rowIndex]->Cells["idProducts"]->Value = reader["ProductID"] != DBNull::Value ? reader["ProductID"] : 0;
            dataGridView->Rows[rowIndex]->Cells["nameProduct"]->Value = reader["ProductName"] != DBNull::Value ? reader["ProductName"] : "";

            // تحميل الصورة من المسار (String)
            if (reader["Photo"] != DBNull::Value) {
                String^ imagePath = reader["Photo"]->ToString();
                if (System::IO::File::Exists(imagePath)) {
                    dataGridView->Rows[rowIndex]->Cells["Photo"]->Value = gcnew Bitmap(imagePath);
                }
                else {
                    dataGridView->Rows[rowIndex]->Cells["Photo"]->Value = nullptr;
                }
            }
            else {
                dataGridView->Rows[rowIndex]->Cells["Photo"]->Value = nullptr;
            }

            dataGridView->Rows[rowIndex]->Cells["BuyingPrice"]->Value = reader["BuyingPrice"] != DBNull::Value ? Convert::ToDecimal(reader["BuyingPrice"]) : Convert::ToDecimal(0.0);
            dataGridView->Rows[rowIndex]->Cells["QTY"]->Value = reader["Quantity"] != DBNull::Value ? Convert::ToInt32(reader["Quantity"]) : 0;
            dataGridView->Rows[rowIndex]->Cells["SellingPrice"]->Value = reader["SellingPrice"] != DBNull::Value ? Convert::ToDecimal(reader["SellingPrice"]) : Convert::ToDecimal(0.0);
            dataGridView->Rows[rowIndex]->Cells["DiscountedPrice"]->Value = reader["DiscountedPrice"] != DBNull::Value ? Convert::ToDecimal(reader["DiscountedPrice"]) : Convert::ToDecimal(0.0);
            dataGridView->Rows[rowIndex]->Cells["CategoryName"]->Value = reader["CategoryName"] != DBNull::Value ? reader["CategoryName"] : "";
            dataGridView->Rows[rowIndex]->Cells["editProduct"]->Value = editImg;
            dataGridView->Rows[rowIndex]->Cells["delProduct"]->Value = delImg;
        }
        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error DataBase: " + ex->Message);
    }



}

void ClientController::LoadProductCards(FlowLayoutPanel^ flowPanel, String^ searchText)
{
    SqlConnection^ conn = Database::GetCon();
    String^ query = "SELECT ProductID, ProductName, Photo, BuyingPrice, Quantity, SellingPrice, DiscountedPrice, CategoryName FROM Product";

    if (!String::IsNullOrEmpty(searchText)) {
        query += " WHERE ProductName LIKE @search OR CategoryName LIKE @search";
    }

    try {
        conn->Open();
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        if (!String::IsNullOrEmpty(searchText)) {
            cmd->Parameters->AddWithValue("@search", "%" + searchText + "%");
        }

        SqlDataReader^ reader = cmd->ExecuteReader();
        flowPanel->Controls->Clear(); // إزالة الكروت القديمة

        while (reader->Read()) {
            // إنشاء بطاقة منتج ديناميكية
            Fexa::ProductCard^ card = gcnew Fexa::ProductCard();
            card->SetCardData(
                reader["ProductID"] != DBNull::Value ? reader["ProductID"]->ToString() : "0",
                reader["ProductName"] != DBNull::Value ? reader["ProductName"]->ToString() : "",
                reader["SellingPrice"] != DBNull::Value ? String::Format("{0:F2} EGP", Convert::ToDecimal(reader["SellingPrice"])) : "0.00 EGP",
                reader["DiscountedPrice"] != DBNull::Value ? String::Format("{0:F2} EGP", Convert::ToDecimal(reader["DiscountedPrice"])) : "0.00 EGP"  ,
                reader["Photo"] != DBNull::Value ? reader["Photo"]->ToString() : "",
                reader["Quantity"] != DBNull::Value ? Convert::ToInt32(reader["Quantity"]) : 0
            );

            // إضافة الكارت إلى FlowLayoutPanel
            flowPanel->Controls->Add(card);
        }

        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Database Error: " + ex->Message);
    }
}
void ClientController::LoadOpex(DataGridView^ dataGridView)
{
    if (dataGridView == nullptr) return;

    dataGridView->Rows->Clear(); // مسح البيانات القديمة
    SqlConnection^ con = Database::GetCon();

    try {
        con->Open();
        // اختبار وجود الجدول
        String^ testQuery = "SELECT COUNT(*) FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME = 'Opex'";
        SqlCommand^ testCmd = gcnew SqlCommand(testQuery, con);
        int tableExists = (int)testCmd->ExecuteScalar();
        if (tableExists == 0) {
            MessageBox::Show("Table 'Opex' does not exist in the database!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            con->Close();
            return;
        }

        // جلب البيانات من جدول Opex
        String^ query = "SELECT Id, ProductName, Quantity, Price, ExpenseDate FROM Opex";
        SqlCommand^ cmd = gcnew SqlCommand(query, con);
        SqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            dataGridView->Rows->Add(
                reader["Id"] != DBNull::Value ? Convert::ToInt32(reader["Id"]) : 0, // تحويل Id لـ int
                reader["ProductName"]->ToString(),
                Convert::ToInt32(reader["Quantity"]),
                Convert::ToDecimal(reader["Price"]).ToString("F2") + " EGP",
                Convert::ToDateTime(reader["ExpenseDate"]).ToString("yyyy/MM/dd HH:mm:ss")
            );
        }
        reader->Close(); // إغلاق الـ Reader بعد الانتهاء من القراءة
        con->Close();    // إغلاق الاتصال
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message + "\nConnection String: " + con->ConnectionString, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

}

void ClientController::LoadAdmin(DataGridView^ dataGridView)
{
    SqlConnection^ con = Database::GetCon();
    con->Open();
	String^ query = "SELECT * FROM users";
	SqlCommand^ cmd = gcnew SqlCommand(query, con);
	SqlDataReader^ reader = cmd->ExecuteReader();
    while (reader->Read())
    {
        int rowIndex = dataGridView->Rows->Add();
		
            dataGridView->Rows[rowIndex]->Cells["IdAdimin"]->Value = reader["id"];
			dataGridView->Rows[rowIndex]->Cells["UserName"]->Value = reader["username"];
			dataGridView->Rows[rowIndex]->Cells["Password"]->Value = reader["password"];



		
    }
    reader->Close();
    con->Close();

}