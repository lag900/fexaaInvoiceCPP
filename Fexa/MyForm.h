#pragma once
#include "AddCat.h"
#include "AddClients.h"
#include "AddProducts.h"
#include "ClientController.h"
#include "ProductCard.h"
#include "AddOpex1.h"
#include "AddAdmin.h"


namespace Fexa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;

	 // ^
	// العلامة ^  اسمها "handle" في C++/CLI، وهي تشير إلى كائن Managed.
	// manged هي كائنات يتم إدارتها بواسطة CLR (Common Language Runtime).
	// وبستخدم معاها gcnew لإنشاء كائن جديد.
	// ميزة الـ handle إنها بتسمح لك بالتعامل مع الكائنات بطريقة آمنة من ناحية الذاكرة.

	/// هل  ممكن نستخدم * اه بس لازم تعمل ادارة لذاكرة بنفسك ولو نسيت هتعمل memory leak

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		// متغيّر لـ PrintDocument
		PrintDocument^ pd;

		// كلاس مساعد عشان نحتفظ بالبيانات أثناء الطباعة
		ref class PrintData {
		public:
			int CurrentRowIndex;
		};

		// متغيّر عشان نستخدمه في الطباعة
		PrintData^ printData;
	private: System::Void OnProductAdded(String^ productId, String^ productName, String^ sellingPrice, int quantity, String^ discountedPrice, String^ total) {
		try {
			if (String::IsNullOrEmpty(productName) || String::IsNullOrEmpty(sellingPrice) ||
				String::IsNullOrEmpty(discountedPrice) || String::IsNullOrEmpty(total) || quantity <= 0) {
				MessageBox::Show("Please provide valid product details.", "Invalid Input",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Show confirmation
		

			// Check if DataGridView exists
			if (dataInv == nullptr) {
				MessageBox::Show("Invoice DataGridView is not initialized.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Ensure DataGridView has the required columns
			if (dataInv->Columns->Count < 5) {
				MessageBox::Show("DataGridView does not have enough columns.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			// Add a new row
			int rowIndex = dataInv->Rows->Add();
			DataGridViewRow^ row = dataInv->Rows[rowIndex];

			row->Cells[0]->Value = productName;          // Column 0: Product Name
			row->Cells[1]->Value = quantity.ToString();  // Column 1: Quantity
			row->Cells[2]->Value = sellingPrice;         // Column 2: Selling Price
			row->Cells[3]->Value = discountedPrice;      // Column 3: Discounted Price
			row->Cells[4]->Value = total;                // Column 4: Total

			// Refresh the DataGridView
			dataInv->Refresh();

			// Update total sum
			lblTotalSum->Text = String::Format("{0:F2} EGP", CalculateTotalSum());
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error adding product: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: Decimal CalculateTotalSum() {
		// دي المتغيّر اللي هنحط فيه الإجمالي الكلي، بنبدأه بصفر
		Decimal totalSum = 0;
		try {
			// بنتأكد إن الـ DataGridView مش فاضي وفيه صفوف
			if (dataInv != nullptr && dataInv->Rows->Count > 0) {
				// بنلف على كل صف في الـ DataGridView
				for each (DataGridViewRow ^ row in dataInv->Rows) {
					// لو الصف ده بتاع "إضافة صف جديد" (Placeholder)، بنتخطاه عشان ميتحسبش
					if (row->IsNewRow) continue;

					// بنتأكد إن خلية الإجمالي (Total) فيها قيمة مش فاضية
					if (row->Cells["Total"]->Value != nullptr) {
						// بناخد القيمة من عمود Total وبنشيل أي مسافات زيادة وبنشيل " EGP"
						String^ totalText = row->Cells["Total"]->Value->ToString()->Trim()->Replace(" EGP", "");
						Decimal value;
						// بنحاول نحوّل النص لرقم (Decimal)، لو نجح بنضيفه للإجمالي
						if (Decimal::TryParse(totalText, Globalization::NumberStyles::Any,
							Globalization::CultureInfo::InvariantCulture, value)) {
							totalSum += value;
						}
						else {
							// لو القيمة مش رقم صحيح، بنطلّع رسالة تحذير للديباج
							MessageBox::Show("Invalid total value: " + totalText, "Warning",
								MessageBoxButtons::OK, MessageBoxIcon::Warning);
						}
					}
				}
			}
		}
		catch (Exception^ ex) {
			// لو حصل أي خطأ (زي إن العمود Total مش موجود)، بنطلّع رسالة
			MessageBox::Show("Error calculating total: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		// بنرجّع الإجمالي اللي حسبناه
		return totalSum;
	}












	private: System::Windows::Forms::Panel^ panel29;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Button^ AddOpex;
	public: System::Windows::Forms::DataGridView^ dataOpex;
	private: System::Windows::Forms::Panel^ panel34;
	private: System::Windows::Forms::Panel^ panel33;
	private: System::Windows::Forms::Panel^ panel32;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdOpex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductOpex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ QtyOpex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PriceOpex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateOpex;
	private: System::Windows::Forms::DataGridViewImageColumn^ dataGridViewImageColumn2;
	private: System::Windows::Forms::Panel^ panel35;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Button^ AddAdimMain;
	private: System::Windows::Forms::Panel^ panel39;
	private: System::Windows::Forms::Panel^ panel37;
	private: System::Windows::Forms::Panel^ panel38;
	private: System::Windows::Forms::Panel^ panel36;
	public: System::Windows::Forms::DataGridView^ dataAdmin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdAdimin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ UserName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password;
	private: System::Windows::Forms::DataGridViewImageColumn^ DelUser;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
private: System::Windows::Forms::Panel^ panel42;
private: System::Windows::Forms::Panel^ panel26;
private: System::Windows::Forms::Panel^ panel23;
private: System::Windows::Forms::DataGridView^ dataInv;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ qtyIn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Discound;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Total;
private: System::Windows::Forms::DataGridViewImageColumn^ delInv;
private: System::Windows::Forms::Panel^ panel27;
private: System::Windows::Forms::Panel^ panel28;
private: System::Windows::Forms::Label^ lblTotalSum;
private: System::Windows::Forms::Panel^ panel30;
private: System::Windows::Forms::Label^ label19;



















	public: static MyForm^ instance;
    // Move the lambda function outside the constructor and make it a private method of the class.  
    private:  
       System::Drawing::Image^ ByteArrayToImage(array<System::Byte>^ byteArray) {  
           System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(byteArray);  
           return System::Drawing::Image::FromStream(ms);  
       }  

private: System::Drawing::Image^ editImg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameClient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PhoneClient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ EmailClient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CityClient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LoctionClient;
	private: System::Windows::Forms::DataGridViewImageColumn^ editClient;
	private: System::Windows::Forms::DataGridViewImageColumn^ delClient;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox9;

	public: System::Windows::Forms::DataGridView^ dataProduct;

	private: System::Windows::Forms::Panel^ panel21;
	private: System::Windows::Forms::Panel^ panel20;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel19;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel18;
	private: System::Windows::Forms::TextBox^ searchProducts;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ btnAddProductMain;

	public: System::Windows::Forms::DataGridView^ data_cat;
	private:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_Cat;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name_Cat;
	private: System::Windows::Forms::DataGridViewImageColumn^ edit;
	private: System::Windows::Forms::DataGridViewImageColumn^ del;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ SearchCat;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btnAddCat;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ idProducts;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameProduct;
	private: System::Windows::Forms::DataGridViewImageColumn^ Photo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BuyingPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ QTY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SellingPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DiscountedPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CategoryName;
	private: System::Windows::Forms::DataGridViewImageColumn^ editProduct;
	private: System::Windows::Forms::DataGridViewImageColumn^ delProduct;


	private: System::Windows::Forms::Panel^ panel22;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;


private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label22;

private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Panel^ panel24;
private: System::Windows::Forms::ComboBox^ comboCategory;
private: System::Windows::Forms::PictureBox^ pictureBox13;
private: System::Windows::Forms::Panel^ panel25;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ label18;










private: System::Windows::Forms::Button^ btn_admin;
private: System::Windows::Forms::Button^ btnPrint;

private: System::Windows::Forms::Button^ button15;






private: System::Windows::Forms::Button^ button14;


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		// تحميل الكروت
		ClientController::LoadProductCards(flowLayoutPanel2, "");

		// ربط الحدث لكل الكروت بعد التحميل
		BindProductCardEvents();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error loading product cards: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: void BindProductCardEvents() {
	for each (Control ^ control in flowLayoutPanel2->Controls) {
		Fexa::ProductCard^ card = dynamic_cast<Fexa::ProductCard^>(control);
		if (card != nullptr) {
			// إلغاء أي ربط قديم عشان نتجنب التكرار
			card->OnAddToInvoice -= gcnew Fexa::ProductCard::AddToInvoiceHandler(this, &MyForm::OnProductAdded);
			// ربط الحدث
			card->OnAddToInvoice += gcnew Fexa::ProductCard::AddToInvoiceHandler(this, &MyForm::OnProductAdded);
		}
	}
}

	
	private: System::Drawing::Image^ delImg;

    public: MyForm::MyForm(void)  
    {  

       InitializeComponent(); // Always first  
       instance = this;  
       resources = gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);  

  
	   ClientController::LoadOpex(dataOpex);
	   ClientController::LoadClients(dataClient, editImg, delImg);
	   ClientController::LoadCat(data_cat, editImg, delImg);
	   ClientController::LoadProducts(dataProduct, editImg, delImg, ""); 
	   ClientController::LoadAdmin(dataAdmin);

   
    }
	

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pn_title;
	protected:

	protected:

	private: System::Windows::Forms::Button^ close;
	private: System::Windows::Forms::Button^ min;
	protected:



    
	private: System::Windows::Forms::Button^ max;
	private: System::Windows::Forms::Panel^ pn_nav;



	System::ComponentModel::ComponentResourceManager^ resources;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel4;




	private: System::Windows::Forms::FlowLayoutPanel^ flow_das;
	private: System::Windows::Forms::Button^ btn_invoices;
	private: System::Windows::Forms::Button^ btn_Client;
	private: System::Windows::Forms::Button^ btn_items;
	private: System::Windows::Forms::Button^ btn_order;
	private: System::Windows::Forms::Panel^ pn_main;
	private: System::Windows::Forms::Panel^ pn_opex;
	private: System::Windows::Forms::Panel^ pn_orders;
	private: System::Windows::Forms::Panel^ pn_item;
	private: System::Windows::Forms::Panel^ pn_client;
	private: System::Windows::Forms::Panel^ pn_invoice;
	private: System::Windows::Forms::Panel^ pn_home;
	private: System::Windows::Forms::Button^ btn_home;
	private: System::Windows::Forms::Panel^ pn_admin;
	private: System::Windows::Forms::Button^ btn_cat;
	private: System::Windows::Forms::Button^ btn_opex;
	private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Panel^ pn_cat;
     private: System::Windows::Forms::Panel^ panel14;
	 private: System::Windows::Forms::Panel^ panel12;
	 private: System::Windows::Forms::Panel^ panel13;
	 private: System::Windows::Forms::PictureBox^ pictureBox11;
	 private: System::Windows::Forms::TextBox^ textBox2;
	 private: System::Windows::Forms::Button^ btnAddClient;
	 private: System::Windows::Forms::Panel^ panel16;
	 private: System::Windows::Forms::Panel^ panel15;
	 private: System::Windows::Forms::Panel^ panel17;
	 private: System::Windows::Forms::DataGridView^ dataClient;
	 private: System::Windows::Forms::Label^ lbClient;
	 private: System::Windows::Forms::Label^ label10;
	 private: System::Windows::Forms::Label^ label9;
	 private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pn_title = (gcnew System::Windows::Forms::Panel());
			this->min = (gcnew System::Windows::Forms::Button());
			this->max = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->pn_nav = (gcnew System::Windows::Forms::Panel());
			this->flow_das = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btn_home = (gcnew System::Windows::Forms::Button());
			this->btn_cat = (gcnew System::Windows::Forms::Button());
			this->btn_invoices = (gcnew System::Windows::Forms::Button());
			this->btn_Client = (gcnew System::Windows::Forms::Button());
			this->btn_items = (gcnew System::Windows::Forms::Button());
			this->btn_order = (gcnew System::Windows::Forms::Button());
			this->btn_opex = (gcnew System::Windows::Forms::Button());
			this->btn_admin = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pn_main = (gcnew System::Windows::Forms::Panel());
			this->pn_invoice = (gcnew System::Windows::Forms::Panel());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->dataInv = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->qtyIn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Discound = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->delInv = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->lblTotalSum = (gcnew System::Windows::Forms::Label());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel42 = (gcnew System::Windows::Forms::Panel());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->btnPrint = (gcnew System::Windows::Forms::Button());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->comboCategory = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->pn_admin = (gcnew System::Windows::Forms::Panel());
			this->dataAdmin = (gcnew System::Windows::Forms::DataGridView());
			this->IdAdimin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->UserName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DelUser = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel39 = (gcnew System::Windows::Forms::Panel());
			this->panel37 = (gcnew System::Windows::Forms::Panel());
			this->panel38 = (gcnew System::Windows::Forms::Panel());
			this->panel36 = (gcnew System::Windows::Forms::Panel());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->AddAdimMain = (gcnew System::Windows::Forms::Button());
			this->pn_opex = (gcnew System::Windows::Forms::Panel());
			this->dataOpex = (gcnew System::Windows::Forms::DataGridView());
			this->IdOpex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductOpex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->QtyOpex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PriceOpex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateOpex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewImageColumn2 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->AddOpex = (gcnew System::Windows::Forms::Button());
			this->pn_cat = (gcnew System::Windows::Forms::Panel());
			this->data_cat = (gcnew System::Windows::Forms::DataGridView());
			this->ID_Cat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name_Cat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->del = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->SearchCat = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnAddCat = (gcnew System::Windows::Forms::Button());
			this->pn_client = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->dataClient = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameClient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PhoneClient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EmailClient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CityClient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LoctionClient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->editClient = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->delClient = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->lbClient = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->btnAddClient = (gcnew System::Windows::Forms::Button());
			this->pn_item = (gcnew System::Windows::Forms::Panel());
			this->dataProduct = (gcnew System::Windows::Forms::DataGridView());
			this->idProducts = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameProduct = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Photo = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->BuyingPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->QTY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SellingPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DiscountedPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CategoryName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->editProduct = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->delProduct = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->searchProducts = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->btnAddProductMain = (gcnew System::Windows::Forms::Button());
			this->pn_home = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pn_orders = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pn_title->SuspendLayout();
			this->pn_nav->SuspendLayout();
			this->flow_das->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->pn_main->SuspendLayout();
			this->pn_invoice->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel23->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataInv))->BeginInit();
			this->panel27->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel30->SuspendLayout();
			this->panel22->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			this->panel24->SuspendLayout();
			this->pn_admin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataAdmin))->BeginInit();
			this->panel37->SuspendLayout();
			this->panel35->SuspendLayout();
			this->pn_opex->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataOpex))->BeginInit();
			this->panel29->SuspendLayout();
			this->pn_cat->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_cat))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			this->pn_client->SuspendLayout();
			this->panel17->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataClient))->BeginInit();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			this->pn_item->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataProduct))->BeginInit();
			this->panel19->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			this->pn_home->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->pn_orders->SuspendLayout();
			this->SuspendLayout();
			// 
			// pn_title
			// 
			this->pn_title->BackColor = System::Drawing::Color::White;
			this->pn_title->Controls->Add(this->min);
			this->pn_title->Controls->Add(this->max);
			this->pn_title->Controls->Add(this->close);
			this->pn_title->Dock = System::Windows::Forms::DockStyle::Top;
			this->pn_title->Location = System::Drawing::Point(233, 0);
			this->pn_title->Name = L"pn_title";
			this->pn_title->Size = System::Drawing::Size(953, 59);
			this->pn_title->TabIndex = 1;
			// 
			// min
			// 
			this->min->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"min.BackgroundImage")));
			this->min->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->min->FlatAppearance->BorderSize = 0;
			this->min->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->min->ForeColor = System::Drawing::Color::Transparent;
			this->min->Location = System::Drawing::Point(776, 0);
			this->min->Margin = System::Windows::Forms::Padding(0);
			this->min->Name = L"min";
			this->min->Size = System::Drawing::Size(57, 57);
			this->min->TabIndex = 0;
			this->min->UseVisualStyleBackColor = true;
			this->min->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// max
			// 
			this->max->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->max->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max.BackgroundImage")));
			this->max->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->max->FlatAppearance->BorderSize = 0;
			this->max->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->max->ForeColor = System::Drawing::Color::Transparent;
			this->max->Location = System::Drawing::Point(833, 0);
			this->max->Margin = System::Windows::Forms::Padding(0);
			this->max->Name = L"max";
			this->max->Size = System::Drawing::Size(57, 57);
			this->max->TabIndex = 0;
			this->max->UseVisualStyleBackColor = true;
			this->max->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// close
			// 
			this->close->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.BackgroundImage")));
			this->close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->close->FlatAppearance->BorderSize = 0;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->ForeColor = System::Drawing::Color::Transparent;
			this->close->Location = System::Drawing::Point(896, 0);
			this->close->Margin = System::Windows::Forms::Padding(0);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(57, 57);
			this->close->TabIndex = 0;
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &MyForm::close_Click);
			this->close->MouseLeave += gcnew System::EventHandler(this, &MyForm::close_MouseLeave);
			this->close->MouseHover += gcnew System::EventHandler(this, &MyForm::close_MouseHover);
			// 
			// pn_nav
			// 
			this->pn_nav->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pn_nav->Controls->Add(this->flow_das);
			this->pn_nav->Controls->Add(this->panel4);
			this->pn_nav->Dock = System::Windows::Forms::DockStyle::Left;
			this->pn_nav->Location = System::Drawing::Point(0, 0);
			this->pn_nav->Name = L"pn_nav";
			this->pn_nav->Size = System::Drawing::Size(233, 721);
			this->pn_nav->TabIndex = 0;
			// 
			// flow_das
			// 
			this->flow_das->Controls->Add(this->btn_home);
			this->flow_das->Controls->Add(this->btn_cat);
			this->flow_das->Controls->Add(this->btn_invoices);
			this->flow_das->Controls->Add(this->btn_Client);
			this->flow_das->Controls->Add(this->btn_items);
			this->flow_das->Controls->Add(this->btn_order);
			this->flow_das->Controls->Add(this->btn_opex);
			this->flow_das->Controls->Add(this->btn_admin);
			this->flow_das->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flow_das->Location = System::Drawing::Point(0, 143);
			this->flow_das->Name = L"flow_das";
			this->flow_das->Size = System::Drawing::Size(233, 578);
			this->flow_das->TabIndex = 3;
			// 
			// btn_home
			// 
			this->btn_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_home->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_home->FlatAppearance->BorderSize = 0;
			this->btn_home->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_home->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_home->ForeColor = System::Drawing::Color::Black;
			this->btn_home->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_home.Image")));
			this->btn_home->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_home->Location = System::Drawing::Point(3, 3);
			this->btn_home->Name = L"btn_home";
			this->btn_home->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_home->Size = System::Drawing::Size(230, 52);
			this->btn_home->TabIndex = 1;
			this->btn_home->Text = L"Home";
			this->btn_home->UseVisualStyleBackColor = true;
			this->btn_home->Click += gcnew System::EventHandler(this, &MyForm::btn_home_Click_1);
			this->btn_home->MouseHover += gcnew System::EventHandler(this, &MyForm::btn_home_h);
			// 
			// btn_cat
			// 
			this->btn_cat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_cat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_cat->FlatAppearance->BorderSize = 0;
			this->btn_cat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cat->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cat->ForeColor = System::Drawing::Color::Black;
			this->btn_cat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_cat.Image")));
			this->btn_cat->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_cat->Location = System::Drawing::Point(3, 61);
			this->btn_cat->Name = L"btn_cat";
			this->btn_cat->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_cat->Size = System::Drawing::Size(230, 52);
			this->btn_cat->TabIndex = 2;
			this->btn_cat->Text = L"Category ";
			this->btn_cat->UseVisualStyleBackColor = true;
			this->btn_cat->Click += gcnew System::EventHandler(this, &MyForm::btn_cat_Click);
		
			// 
			// btn_invoices
			// 
			this->btn_invoices->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_invoices->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_invoices->FlatAppearance->BorderSize = 0;
			this->btn_invoices->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_invoices->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_invoices->ForeColor = System::Drawing::Color::Black;
			this->btn_invoices->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_invoices.Image")));
			this->btn_invoices->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_invoices->Location = System::Drawing::Point(3, 119);
			this->btn_invoices->Name = L"btn_invoices";
			this->btn_invoices->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_invoices->Size = System::Drawing::Size(230, 52);
			this->btn_invoices->TabIndex = 0;
			this->btn_invoices->Text = L"Invoices";
			this->btn_invoices->UseVisualStyleBackColor = true;
			this->btn_invoices->Click += gcnew System::EventHandler(this, &MyForm::btn_invoices_Click);
			// 
			// btn_Client
			// 
			this->btn_Client->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_Client->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_Client->FlatAppearance->BorderSize = 0;
			this->btn_Client->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Client->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Client->ForeColor = System::Drawing::Color::Black;
			this->btn_Client->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_Client.Image")));
			this->btn_Client->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_Client->Location = System::Drawing::Point(3, 177);
			this->btn_Client->Name = L"btn_Client";
			this->btn_Client->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_Client->Size = System::Drawing::Size(230, 52);
			this->btn_Client->TabIndex = 0;
			this->btn_Client->Text = L"Clients";
			this->btn_Client->UseVisualStyleBackColor = true;
			this->btn_Client->Click += gcnew System::EventHandler(this, &MyForm::btn_Client_Click);
			// 
			// btn_items
			// 
			this->btn_items->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_items->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_items->FlatAppearance->BorderSize = 0;
			this->btn_items->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_items->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_items->ForeColor = System::Drawing::Color::Black;
			this->btn_items->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_items.Image")));
			this->btn_items->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_items->Location = System::Drawing::Point(3, 235);
			this->btn_items->Name = L"btn_items";
			this->btn_items->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_items->Size = System::Drawing::Size(230, 52);
			this->btn_items->TabIndex = 0;
			this->btn_items->Text = L"Products";
			this->btn_items->UseVisualStyleBackColor = true;
			this->btn_items->Click += gcnew System::EventHandler(this, &MyForm::btn_items_Click);
			// 
			// btn_order
			// 
			this->btn_order->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_order->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_order->FlatAppearance->BorderSize = 0;
			this->btn_order->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_order->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_order->ForeColor = System::Drawing::Color::Black;
			this->btn_order->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_order.Image")));
			this->btn_order->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_order->Location = System::Drawing::Point(3, 293);
			this->btn_order->Name = L"btn_order";
			this->btn_order->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_order->Size = System::Drawing::Size(230, 52);
			this->btn_order->TabIndex = 0;
			this->btn_order->Text = L"Orders";
			this->btn_order->UseVisualStyleBackColor = true;
			this->btn_order->Click += gcnew System::EventHandler(this, &MyForm::btn_order_Click);
			// 
			// btn_opex
			// 
			this->btn_opex->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_opex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_opex->FlatAppearance->BorderSize = 0;
			this->btn_opex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_opex->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_opex->ForeColor = System::Drawing::Color::Black;
			this->btn_opex->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_opex.Image")));
			this->btn_opex->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opex->Location = System::Drawing::Point(3, 351);
			this->btn_opex->Name = L"btn_opex";
			this->btn_opex->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_opex->Size = System::Drawing::Size(230, 52);
			this->btn_opex->TabIndex = 0;
			this->btn_opex->Text = L"OPEX";
			this->btn_opex->UseVisualStyleBackColor = true;
			this->btn_opex->Click += gcnew System::EventHandler(this, &MyForm::btn_opex_Click_1);
			// 
			// btn_admin
			// 
			this->btn_admin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_admin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_admin->FlatAppearance->BorderSize = 0;
			this->btn_admin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_admin->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_admin->ForeColor = System::Drawing::Color::Black;
			this->btn_admin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_admin.Image")));
			this->btn_admin->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_admin->Location = System::Drawing::Point(3, 409);
			this->btn_admin->Name = L"btn_admin";
			this->btn_admin->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_admin->Size = System::Drawing::Size(230, 52);
			this->btn_admin->TabIndex = 0;
			this->btn_admin->Text = L"Admins";
			this->btn_admin->UseVisualStyleBackColor = true;
			this->btn_admin->Click += gcnew System::EventHandler(this, &MyForm::btn_admin_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(233, 143);
			this->panel4->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(45, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(135, 81);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_1);
			// 
			// pn_main
			// 
			this->pn_main->Controls->Add(this->pn_invoice);
			this->pn_main->Controls->Add(this->pn_admin);
			this->pn_main->Controls->Add(this->pn_opex);
			this->pn_main->Controls->Add(this->pn_cat);
			this->pn_main->Controls->Add(this->pn_client);
			this->pn_main->Controls->Add(this->pn_item);
			this->pn_main->Controls->Add(this->pn_home);
			this->pn_main->Controls->Add(this->pn_orders);
			this->pn_main->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_main->Location = System::Drawing::Point(233, 59);
			this->pn_main->Name = L"pn_main";
			this->pn_main->Size = System::Drawing::Size(953, 662);
			this->pn_main->TabIndex = 2;
			// 
			// pn_invoice
			// 
			this->pn_invoice->Controls->Add(this->panel26);
			this->pn_invoice->Controls->Add(this->panel23);
			this->pn_invoice->Controls->Add(this->panel22);
			this->pn_invoice->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_invoice->Location = System::Drawing::Point(0, 0);
			this->pn_invoice->Name = L"pn_invoice";
			this->pn_invoice->Size = System::Drawing::Size(953, 662);
			this->pn_invoice->TabIndex = 4;
			// 
			// panel26
			// 
			this->panel26->Controls->Add(this->flowLayoutPanel2);
			this->panel26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel26->Location = System::Drawing::Point(0, 124);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(448, 538);
			this->panel26->TabIndex = 2;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->AutoScroll = true;
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(448, 538);
			this->flowLayoutPanel2->TabIndex = 9;
			// 
			// panel23
			// 
			this->panel23->Controls->Add(this->dataInv);
			this->panel23->Controls->Add(this->panel27);
			this->panel23->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel23->Location = System::Drawing::Point(448, 124);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(505, 538);
			this->panel23->TabIndex = 1;
			// 
			// dataInv
			// 
			this->dataInv->AllowUserToAddRows = false;
			this->dataInv->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataInv->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataInv->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataInv->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataInv->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataInv->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataInv->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedHorizontal;
			this->dataInv->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->dataInv->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Red;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataInv->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataInv->ColumnHeadersHeight = 40;
			this->dataInv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn3,
					this->qtyIn, this->Price, this->Discound, this->Total, this->delInv
			});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataInv->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataInv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataInv->EnableHeadersVisualStyles = false;
			this->dataInv->GridColor = System::Drawing::SystemColors::GrayText;
			this->dataInv->Location = System::Drawing::Point(0, 0);
			this->dataInv->Name = L"dataInv";
			this->dataInv->ReadOnly = true;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataInv->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataInv->RowHeadersVisible = false;
			this->dataInv->RowHeadersWidth = 10;
			this->dataInv->RowTemplate->Height = 40;
			this->dataInv->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataInv->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataInv->Size = System::Drawing::Size(505, 425);
			this->dataInv->TabIndex = 7;
			this->dataInv->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataInv_CellContentClick_1);
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->dataGridViewTextBoxColumn3->FillWeight = 554.4884F;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Item";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// qtyIn
			// 
			this->qtyIn->FillWeight = 51.2902F;
			this->qtyIn->HeaderText = L"QTY";
			this->qtyIn->MinimumWidth = 6;
			this->qtyIn->Name = L"qtyIn";
			this->qtyIn->ReadOnly = true;
			// 
			// Price
			// 
			this->Price->FillWeight = 51.2902F;
			this->Price->HeaderText = L"Price";
			this->Price->MinimumWidth = 6;
			this->Price->Name = L"Price";
			this->Price->ReadOnly = true;
			// 
			// Discound
			// 
			this->Discound->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Discound->FillWeight = 51.2902F;
			this->Discound->HeaderText = L"Discound";
			this->Discound->MinimumWidth = 6;
			this->Discound->Name = L"Discound";
			this->Discound->ReadOnly = true;
			this->Discound->Width = 125;
			// 
			// Total
			// 
			this->Total->FillWeight = 51.2902F;
			this->Total->HeaderText = L"Total";
			this->Total->MinimumWidth = 6;
			this->Total->Name = L"Total";
			this->Total->ReadOnly = true;
			// 
			// delInv
			// 
			this->delInv->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->delInv->FillWeight = 30;
			this->delInv->HeaderText = L"";
			this->delInv->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delInv.Image")));
			this->delInv->MinimumWidth = 30;
			this->delInv->Name = L"delInv";
			this->delInv->ReadOnly = true;
			this->delInv->Width = 30;
			// 
			// panel27
			// 
			this->panel27->Controls->Add(this->panel28);
			this->panel27->Controls->Add(this->panel30);
			this->panel27->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel27->Location = System::Drawing::Point(0, 425);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(505, 113);
			this->panel27->TabIndex = 8;
			// 
			// panel28
			// 
			this->panel28->AutoSize = true;
			this->panel28->BackColor = System::Drawing::Color::Transparent;
			this->panel28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel28->Controls->Add(this->lblTotalSum);
			this->panel28->ForeColor = System::Drawing::Color::Red;
			this->panel28->Location = System::Drawing::Point(130, 64);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(143, 44);
			this->panel28->TabIndex = 0;
			// 
			// lblTotalSum
			// 
			this->lblTotalSum->AutoSize = true;
			this->lblTotalSum->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalSum->ForeColor = System::Drawing::Color::Black;
			this->lblTotalSum->Location = System::Drawing::Point(52, 7);
			this->lblTotalSum->Name = L"lblTotalSum";
			this->lblTotalSum->Size = System::Drawing::Size(51, 25);
			this->lblTotalSum->TabIndex = 18;
			this->lblTotalSum->Text = L"0.00";
			// 
			// panel30
			// 
			this->panel30->BackColor = System::Drawing::Color::Red;
			this->panel30->Controls->Add(this->label19);
			this->panel30->Location = System::Drawing::Point(6, 64);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(143, 44);
			this->panel30->TabIndex = 0;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Transparent;
			this->label19->Location = System::Drawing::Point(39, 9);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(58, 25);
			this->label19->TabIndex = 18;
			this->label19->Text = L"Total";
			// 
			// panel22
			// 
			this->panel22->Controls->Add(this->panel42);
			this->panel22->Controls->Add(this->button15);
			this->panel22->Controls->Add(this->button14);
			this->panel22->Controls->Add(this->btnPrint);
			this->panel22->Controls->Add(this->pictureBox13);
			this->panel22->Controls->Add(this->panel25);
			this->panel22->Controls->Add(this->textBox1);
			this->panel22->Controls->Add(this->label18);
			this->panel22->Controls->Add(this->label22);
			this->panel22->Controls->Add(this->label20);
			this->panel22->Controls->Add(this->panel24);
			this->panel22->Controls->Add(this->label17);
			this->panel22->Controls->Add(this->dateTimePicker1);
			this->panel22->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel22->Location = System::Drawing::Point(0, 0);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(953, 124);
			this->panel22->TabIndex = 0;
			// 
			// panel42
			// 
			this->panel42->Location = System::Drawing::Point(0, 124);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(475, 201);
			this->panel42->TabIndex = 0;
			// 
			// button15
			// 
			this->button15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button15->BackColor = System::Drawing::Color::Red;
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8, System::Drawing::FontStyle::Bold));
			this->button15->ForeColor = System::Drawing::Color::White;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(829, 71);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(121, 33);
			this->button15->TabIndex = 79;
			this->button15->Text = L"Delete";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::dellAll);
			// 
			// button14
			// 
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button14->BackColor = System::Drawing::Color::Red;
			this->button14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8, System::Drawing::FontStyle::Bold));
			this->button14->ForeColor = System::Drawing::Color::White;
			this->button14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.Image")));
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(703, 72);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(121, 33);
			this->button14->TabIndex = 79;
			this->button14->Text = L"Save";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::btn_newCat_Click);
			this->button14->MouseHover += gcnew System::EventHandler(this, &MyForm::button14_MouseHover);
			// 
			// btnPrint
			// 
			this->btnPrint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnPrint->BackColor = System::Drawing::Color::Red;
			this->btnPrint->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnPrint->FlatAppearance->BorderSize = 0;
			this->btnPrint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPrint->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8, System::Drawing::FontStyle::Bold));
			this->btnPrint->ForeColor = System::Drawing::Color::White;
			this->btnPrint->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPrint.Image")));
			this->btnPrint->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPrint->Location = System::Drawing::Point(576, 72);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(121, 33);
			this->btnPrint->TabIndex = 79;
			this->btnPrint->Text = L"Print";
			this->btnPrint->UseVisualStyleBackColor = false;
			this->btnPrint->Click += gcnew System::EventHandler(this, &MyForm::btnPrint_Click);
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(12, 66);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(32, 27);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox13->TabIndex = 76;
			this->pictureBox13->TabStop = false;
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::Red;
			this->panel25->Location = System::Drawing::Point(28, 95);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(248, 3);
			this->panel25->TabIndex = 78;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(53, 70);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(227, 41);
			this->textBox1->TabIndex = 77;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label18->Location = System::Drawing::Point(40, 43);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(53, 20);
			this->label18->TabIndex = 75;
			this->label18->Text = L"Search";
			this->label18->Click += gcnew System::EventHandler(this, &MyForm::label18_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label22->Location = System::Drawing::Point(284, 43);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(41, 20);
			this->label22->TabIndex = 75;
			this->label22->Text = L"Date";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label20->Location = System::Drawing::Point(402, 43);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(69, 20);
			this->label20->TabIndex = 75;
			this->label20->Text = L"Category";
			// 
			// panel24
			// 
			this->panel24->Controls->Add(this->comboCategory);
			this->panel24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.2F));
			this->panel24->Location = System::Drawing::Point(406, 76);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(164, 27);
			this->panel24->TabIndex = 74;
			// 
			// comboCategory
			// 
			this->comboCategory->Location = System::Drawing::Point(0, -7);
			this->comboCategory->Name = L"comboCategory";
			this->comboCategory->Size = System::Drawing::Size(161, 33);
			this->comboCategory->TabIndex = 18;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(24, 16);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(79, 25);
			this->label17->TabIndex = 18;
			this->label17->Text = L"Invoices";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 7.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(282, 76);
			this->dateTimePicker1->MinDate = System::DateTime(2025, 5, 25, 23, 59, 59, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dateTimePicker1->Size = System::Drawing::Size(118, 25);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->Value = System::DateTime(2025, 5, 25, 23, 59, 59, 0);
			// 
			// pn_admin
			// 
			this->pn_admin->Controls->Add(this->dataAdmin);
			this->pn_admin->Controls->Add(this->panel39);
			this->pn_admin->Controls->Add(this->panel37);
			this->pn_admin->Controls->Add(this->panel36);
			this->pn_admin->Controls->Add(this->panel35);
			this->pn_admin->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_admin->Location = System::Drawing::Point(0, 0);
			this->pn_admin->Name = L"pn_admin";
			this->pn_admin->Size = System::Drawing::Size(953, 662);
			this->pn_admin->TabIndex = 10;
			this->pn_admin->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pn_admin_Paint);
			// 
			// dataAdmin
			// 
			this->dataAdmin->AllowUserToAddRows = false;
			this->dataAdmin->AllowUserToDeleteRows = false;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataAdmin->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataAdmin->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataAdmin->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataAdmin->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataAdmin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataAdmin->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedHorizontal;
			this->dataAdmin->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->dataAdmin->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::Red;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataAdmin->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataAdmin->ColumnHeadersHeight = 40;
			this->dataAdmin->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->IdAdimin, this->UserName,
					this->Password, this->DelUser
			});
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle9->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataAdmin->DefaultCellStyle = dataGridViewCellStyle9;
			this->dataAdmin->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataAdmin->EnableHeadersVisualStyles = false;
			this->dataAdmin->GridColor = System::Drawing::SystemColors::GrayText;
			this->dataAdmin->Location = System::Drawing::Point(45, 153);
			this->dataAdmin->Name = L"dataAdmin";
			this->dataAdmin->ReadOnly = true;
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle10->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataAdmin->RowHeadersDefaultCellStyle = dataGridViewCellStyle10;
			this->dataAdmin->RowHeadersVisible = false;
			this->dataAdmin->RowHeadersWidth = 10;
			this->dataAdmin->RowTemplate->Height = 40;
			this->dataAdmin->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataAdmin->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataAdmin->Size = System::Drawing::Size(863, 481);
			this->dataAdmin->TabIndex = 6;
			this->dataAdmin->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataAdmin_CellContentClick);
			// 
			// IdAdimin
			// 
			this->IdAdimin->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->IdAdimin->DefaultCellStyle = dataGridViewCellStyle7;
			this->IdAdimin->FillWeight = 90;
			this->IdAdimin->HeaderText = L"ID";
			this->IdAdimin->MinimumWidth = 2;
			this->IdAdimin->Name = L"IdAdimin";
			this->IdAdimin->ReadOnly = true;
			this->IdAdimin->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->IdAdimin->Width = 40;
			// 
			// UserName
			// 
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->UserName->DefaultCellStyle = dataGridViewCellStyle8;
			this->UserName->HeaderText = L"User Name";
			this->UserName->MinimumWidth = 6;
			this->UserName->Name = L"UserName";
			this->UserName->ReadOnly = true;
			// 
			// Password
			// 
			this->Password->HeaderText = L"Password";
			this->Password->MinimumWidth = 6;
			this->Password->Name = L"Password";
			this->Password->ReadOnly = true;
			// 
			// DelUser
			// 
			this->DelUser->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->DelUser->HeaderText = L"";
			this->DelUser->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DelUser.Image")));
			this->DelUser->MinimumWidth = 50;
			this->DelUser->Name = L"DelUser";
			this->DelUser->ReadOnly = true;
			this->DelUser->Width = 50;
			// 
			// panel39
			// 
			this->panel39->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel39->Location = System::Drawing::Point(45, 634);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(863, 28);
			this->panel39->TabIndex = 4;
			// 
			// panel37
			// 
			this->panel37->Controls->Add(this->panel38);
			this->panel37->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel37->Location = System::Drawing::Point(0, 153);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(45, 509);
			this->panel37->TabIndex = 2;
			// 
			// panel38
			// 
			this->panel38->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel38->Location = System::Drawing::Point(0, 0);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(45, 509);
			this->panel38->TabIndex = 3;
			// 
			// panel36
			// 
			this->panel36->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel36->Location = System::Drawing::Point(908, 153);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(45, 509);
			this->panel36->TabIndex = 1;
			// 
			// panel35
			// 
			this->panel35->Controls->Add(this->label23);
			this->panel35->Controls->Add(this->label25);
			this->panel35->Controls->Add(this->AddAdimMain);
			this->panel35->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel35->Location = System::Drawing::Point(0, 0);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(953, 153);
			this->panel35->TabIndex = 0;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(43, 8);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(82, 31);
			this->label23->TabIndex = 16;
			this->label23->Text = L"Admin";
			// 
			// label25
			// 
			this->label25->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label25->Location = System::Drawing::Point(712, 69);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(112, 28);
			this->label25->TabIndex = 17;
			this->label25->Text = L"Add Admin";
			// 
			// AddAdimMain
			// 
			this->AddAdimMain->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->AddAdimMain->BackColor = System::Drawing::Color::Red;
			this->AddAdimMain->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->AddAdimMain->FlatAppearance->BorderSize = 0;
			this->AddAdimMain->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddAdimMain->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->AddAdimMain->ForeColor = System::Drawing::Color::Transparent;
			this->AddAdimMain->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddAdimMain.Image")));
			this->AddAdimMain->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->AddAdimMain->Location = System::Drawing::Point(717, 100);
			this->AddAdimMain->Name = L"AddAdimMain";
			this->AddAdimMain->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->AddAdimMain->Size = System::Drawing::Size(193, 45);
			this->AddAdimMain->TabIndex = 15;
			this->AddAdimMain->Text = L"Add";
			this->AddAdimMain->UseVisualStyleBackColor = false;
			this->AddAdimMain->Click += gcnew System::EventHandler(this, &MyForm::AddAdimMain_Click);
			// 
			// pn_opex
			// 
			this->pn_opex->Controls->Add(this->dataOpex);
			this->pn_opex->Controls->Add(this->panel34);
			this->pn_opex->Controls->Add(this->panel33);
			this->pn_opex->Controls->Add(this->panel32);
			this->pn_opex->Controls->Add(this->panel29);
			this->pn_opex->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_opex->Location = System::Drawing::Point(0, 0);
			this->pn_opex->Name = L"pn_opex";
			this->pn_opex->Size = System::Drawing::Size(953, 662);
			this->pn_opex->TabIndex = 9;
			this->pn_opex->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pn_opex_Paint);
			// 
			// dataOpex
			// 
			this->dataOpex->AllowUserToAddRows = false;
			this->dataOpex->AllowUserToDeleteRows = false;
			dataGridViewCellStyle11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataOpex->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle11;
			this->dataOpex->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataOpex->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataOpex->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataOpex->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataOpex->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedHorizontal;
			this->dataOpex->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->dataOpex->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle12->BackColor = System::Drawing::Color::Red;
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataOpex->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle12;
			this->dataOpex->ColumnHeadersHeight = 40;
			this->dataOpex->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->IdOpex, this->ProductOpex,
					this->QtyOpex, this->PriceOpex, this->DateOpex, this->dataGridViewImageColumn2
			});
			dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle15->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle15->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle15->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle15->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle15->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataOpex->DefaultCellStyle = dataGridViewCellStyle15;
			this->dataOpex->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataOpex->EnableHeadersVisualStyles = false;
			this->dataOpex->GridColor = System::Drawing::SystemColors::GrayText;
			this->dataOpex->Location = System::Drawing::Point(47, 161);
			this->dataOpex->Name = L"dataOpex";
			this->dataOpex->ReadOnly = true;
			dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle16->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataOpex->RowHeadersDefaultCellStyle = dataGridViewCellStyle16;
			this->dataOpex->RowHeadersVisible = false;
			this->dataOpex->RowHeadersWidth = 10;
			this->dataOpex->RowTemplate->Height = 40;
			this->dataOpex->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataOpex->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataOpex->Size = System::Drawing::Size(855, 467);
			this->dataOpex->TabIndex = 5;
			// 
			// IdOpex
			// 
			this->IdOpex->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->IdOpex->DefaultCellStyle = dataGridViewCellStyle13;
			this->IdOpex->FillWeight = 90;
			this->IdOpex->HeaderText = L"ID";
			this->IdOpex->MinimumWidth = 2;
			this->IdOpex->Name = L"IdOpex";
			this->IdOpex->ReadOnly = true;
			this->IdOpex->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->IdOpex->Width = 40;
			// 
			// ProductOpex
			// 
			dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->ProductOpex->DefaultCellStyle = dataGridViewCellStyle14;
			this->ProductOpex->HeaderText = L"Product";
			this->ProductOpex->MinimumWidth = 6;
			this->ProductOpex->Name = L"ProductOpex";
			this->ProductOpex->ReadOnly = true;
			// 
			// QtyOpex
			// 
			this->QtyOpex->HeaderText = L"Qty";
			this->QtyOpex->MinimumWidth = 6;
			this->QtyOpex->Name = L"QtyOpex";
			this->QtyOpex->ReadOnly = true;
			// 
			// PriceOpex
			// 
			this->PriceOpex->HeaderText = L"Price";
			this->PriceOpex->MinimumWidth = 6;
			this->PriceOpex->Name = L"PriceOpex";
			this->PriceOpex->ReadOnly = true;
			// 
			// DateOpex
			// 
			this->DateOpex->HeaderText = L"Date";
			this->DateOpex->MinimumWidth = 6;
			this->DateOpex->Name = L"DateOpex";
			this->DateOpex->ReadOnly = true;
			// 
			// dataGridViewImageColumn2
			// 
			this->dataGridViewImageColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->dataGridViewImageColumn2->HeaderText = L"";
			this->dataGridViewImageColumn2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dataGridViewImageColumn2.Image")));
			this->dataGridViewImageColumn2->MinimumWidth = 50;
			this->dataGridViewImageColumn2->Name = L"dataGridViewImageColumn2";
			this->dataGridViewImageColumn2->ReadOnly = true;
			this->dataGridViewImageColumn2->Width = 50;
			// 
			// panel34
			// 
			this->panel34->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel34->Location = System::Drawing::Point(47, 628);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(855, 34);
			this->panel34->TabIndex = 4;
			// 
			// panel33
			// 
			this->panel33->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel33->Location = System::Drawing::Point(0, 161);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(47, 501);
			this->panel33->TabIndex = 3;
			// 
			// panel32
			// 
			this->panel32->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel32->Location = System::Drawing::Point(902, 161);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(51, 501);
			this->panel32->TabIndex = 2;
			// 
			// panel29
			// 
			this->panel29->Controls->Add(this->label21);
			this->panel29->Controls->Add(this->label24);
			this->panel29->Controls->Add(this->AddOpex);
			this->panel29->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel29->Location = System::Drawing::Point(0, 0);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(953, 161);
			this->panel29->TabIndex = 1;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(41, 16);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(220, 31);
			this->label21->TabIndex = 13;
			this->label21->Text = L"Operating Expenses";
			// 
			// label24
			// 
			this->label24->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label24->Location = System::Drawing::Point(710, 77);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(102, 28);
			this->label24->TabIndex = 14;
			this->label24->Text = L"Add OPEX";
			// 
			// AddOpex
			// 
			this->AddOpex->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->AddOpex->BackColor = System::Drawing::Color::Red;
			this->AddOpex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->AddOpex->FlatAppearance->BorderSize = 0;
			this->AddOpex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddOpex->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->AddOpex->ForeColor = System::Drawing::Color::Transparent;
			this->AddOpex->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddOpex.Image")));
			this->AddOpex->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->AddOpex->Location = System::Drawing::Point(715, 109);
			this->AddOpex->Name = L"AddOpex";
			this->AddOpex->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->AddOpex->Size = System::Drawing::Size(193, 45);
			this->AddOpex->TabIndex = 11;
			this->AddOpex->Text = L"Add";
			this->AddOpex->UseVisualStyleBackColor = false;
			this->AddOpex->Click += gcnew System::EventHandler(this, &MyForm::AddOpex_Click);
			// 
			// pn_cat
			// 
			this->pn_cat->Controls->Add(this->data_cat);
			this->pn_cat->Controls->Add(this->panel11);
			this->pn_cat->Controls->Add(this->panel10);
			this->pn_cat->Controls->Add(this->panel9);
			this->pn_cat->Controls->Add(this->panel2);
			this->pn_cat->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_cat->Location = System::Drawing::Point(0, 0);
			this->pn_cat->Name = L"pn_cat";
			this->pn_cat->Size = System::Drawing::Size(953, 662);
			this->pn_cat->TabIndex = 7;
			this->pn_cat->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pn_cat_Paint);
			// 
			// data_cat
			// 
			this->data_cat->AllowUserToAddRows = false;
			this->data_cat->AllowUserToDeleteRows = false;
			dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->data_cat->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle17;
			this->data_cat->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->data_cat->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->data_cat->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->data_cat->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->data_cat->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedHorizontal;
			this->data_cat->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->data_cat->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle18->BackColor = System::Drawing::Color::Red;
			dataGridViewCellStyle18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle18->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle18->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle18->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle18->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->data_cat->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle18;
			this->data_cat->ColumnHeadersHeight = 40;
			this->data_cat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ID_Cat, this->name_Cat,
					this->edit, this->del
			});
			dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle21->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle21->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle21->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle21->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle21->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->data_cat->DefaultCellStyle = dataGridViewCellStyle21;
			this->data_cat->Dock = System::Windows::Forms::DockStyle::Fill;
			this->data_cat->EnableHeadersVisualStyles = false;
			this->data_cat->GridColor = System::Drawing::SystemColors::GrayText;
			this->data_cat->Location = System::Drawing::Point(47, 170);
			this->data_cat->Name = L"data_cat";
			this->data_cat->ReadOnly = true;
			dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle22->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle22->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle22->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle22->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->data_cat->RowHeadersDefaultCellStyle = dataGridViewCellStyle22;
			this->data_cat->RowHeadersVisible = false;
			this->data_cat->RowHeadersWidth = 10;
			this->data_cat->RowTemplate->Height = 40;
			this->data_cat->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->data_cat->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->data_cat->Size = System::Drawing::Size(841, 443);
			this->data_cat->TabIndex = 1;
			this->data_cat->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::data_cat_CellContentClick);
			// 
			// ID_Cat
			// 
			this->ID_Cat->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->ID_Cat->DefaultCellStyle = dataGridViewCellStyle19;
			this->ID_Cat->FillWeight = 90;
			this->ID_Cat->HeaderText = L"ID";
			this->ID_Cat->MinimumWidth = 2;
			this->ID_Cat->Name = L"ID_Cat";
			this->ID_Cat->ReadOnly = true;
			this->ID_Cat->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ID_Cat->Width = 40;
			// 
			// name_Cat
			// 
			dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->name_Cat->DefaultCellStyle = dataGridViewCellStyle20;
			this->name_Cat->HeaderText = L"Category";
			this->name_Cat->MinimumWidth = 6;
			this->name_Cat->Name = L"name_Cat";
			this->name_Cat->ReadOnly = true;
			// 
			// edit
			// 
			this->edit->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->edit->FillWeight = 50;
			this->edit->HeaderText = L"";
			this->edit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit.Image")));
			this->edit->MinimumWidth = 50;
			this->edit->Name = L"edit";
			this->edit->ReadOnly = true;
			this->edit->Width = 50;
			// 
			// del
			// 
			this->del->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->del->HeaderText = L"";
			this->del->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"del.Image")));
			this->del->MinimumWidth = 50;
			this->del->Name = L"del";
			this->del->ReadOnly = true;
			this->del->Width = 50;
			// 
			// panel11
			// 
			this->panel11->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel11->Location = System::Drawing::Point(47, 613);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(841, 49);
			this->panel11->TabIndex = 5;
			// 
			// panel10
			// 
			this->panel10->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel10->Location = System::Drawing::Point(888, 170);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(65, 492);
			this->panel10->TabIndex = 4;
			// 
			// panel9
			// 
			this->panel9->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel9->Location = System::Drawing::Point(0, 170);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(47, 492);
			this->panel9->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->pictureBox12);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->panel7);
			this->panel2->Controls->Add(this->SearchCat);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->btnAddCat);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(953, 170);
			this->panel2->TabIndex = 0;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint_1);
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(44, 107);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(32, 27);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox12->TabIndex = 5;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->Click += gcnew System::EventHandler(this, &MyForm::pictureBox12_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label14->Location = System::Drawing::Point(48, 76);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(70, 28);
			this->label14->TabIndex = 20;
			this->label14->Text = L"Search";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Red;
			this->panel7->Location = System::Drawing::Point(53, 144);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(370, 3);
			this->panel7->TabIndex = 19;
			// 
			// SearchCat
			// 
			this->SearchCat->BackColor = System::Drawing::Color::White;
			this->SearchCat->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchCat->ForeColor = System::Drawing::Color::Black;
			this->SearchCat->Location = System::Drawing::Point(86, 117);
			this->SearchCat->Multiline = true;
			this->SearchCat->Name = L"SearchCat";
			this->SearchCat->Size = System::Drawing::Size(334, 40);
			this->SearchCat->TabIndex = 18;
			this->SearchCat->TextChanged += gcnew System::EventHandler(this, &MyForm::SearchCat_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(41, 16);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(110, 31);
			this->label11->TabIndex = 13;
			this->label11->Text = L"Category";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// label12
			// 
			this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label12->Location = System::Drawing::Point(710, 77);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(134, 28);
			this->label12->TabIndex = 14;
			this->label12->Text = L"Add Category";
			// 
			// btnAddCat
			// 
			this->btnAddCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddCat->BackColor = System::Drawing::Color::Red;
			this->btnAddCat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAddCat->FlatAppearance->BorderSize = 0;
			this->btnAddCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCat->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btnAddCat->ForeColor = System::Drawing::Color::Transparent;
			this->btnAddCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddCat.Image")));
			this->btnAddCat->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddCat->Location = System::Drawing::Point(715, 109);
			this->btnAddCat->Name = L"btnAddCat";
			this->btnAddCat->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btnAddCat->Size = System::Drawing::Size(193, 45);
			this->btnAddCat->TabIndex = 11;
			this->btnAddCat->Text = L"Add";
			this->btnAddCat->UseVisualStyleBackColor = false;
			this->btnAddCat->Click += gcnew System::EventHandler(this, &MyForm::btnAddCat_Click);
			// 
			// pn_client
			// 
			this->pn_client->Controls->Add(this->panel17);
			this->pn_client->Controls->Add(this->panel16);
			this->pn_client->Controls->Add(this->panel15);
			this->pn_client->Controls->Add(this->panel14);
			this->pn_client->Controls->Add(this->panel12);
			this->pn_client->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_client->Location = System::Drawing::Point(0, 0);
			this->pn_client->Name = L"pn_client";
			this->pn_client->Size = System::Drawing::Size(953, 662);
			this->pn_client->TabIndex = 5;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->dataClient);
			this->panel17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel17->Location = System::Drawing::Point(44, 170);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(858, 449);
			this->panel17->TabIndex = 2;
			// 
			// dataClient
			// 
			this->dataClient->AllowUserToAddRows = false;
			this->dataClient->AllowUserToDeleteRows = false;
			dataGridViewCellStyle23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataClient->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle23;
			this->dataClient->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataClient->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataClient->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataClient->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataClient->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedHorizontal;
			this->dataClient->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->dataClient->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle24->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle24->BackColor = System::Drawing::Color::Red;
			dataGridViewCellStyle24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle24->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle24->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle24->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataClient->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle24;
			this->dataClient->ColumnHeadersHeight = 40;
			this->dataClient->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->dataGridViewTextBoxColumn1,
					this->NameClient, this->PhoneClient, this->EmailClient, this->CityClient, this->LoctionClient, this->editClient, this->delClient
			});
			dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle25->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle25->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle25->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle25->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle25->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataClient->DefaultCellStyle = dataGridViewCellStyle25;
			this->dataClient->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataClient->EnableHeadersVisualStyles = false;
			this->dataClient->GridColor = System::Drawing::SystemColors::GrayText;
			this->dataClient->Location = System::Drawing::Point(0, 0);
			this->dataClient->Name = L"dataClient";
			this->dataClient->ReadOnly = true;
			dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle26->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle26->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle26->SelectionBackColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle26->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle26->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataClient->RowHeadersDefaultCellStyle = dataGridViewCellStyle26;
			this->dataClient->RowHeadersVisible = false;
			this->dataClient->RowHeadersWidth = 10;
			this->dataClient->RowTemplate->Height = 40;
			this->dataClient->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataClient->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataClient->Size = System::Drawing::Size(858, 449);
			this->dataClient->TabIndex = 2;
			this->dataClient->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataClient_CellContentClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->dataGridViewTextBoxColumn1->FillWeight = 10;
			this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 3;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn1->Width = 30;
			// 
			// NameClient
			// 
			this->NameClient->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->NameClient->FillWeight = 359.6492F;
			this->NameClient->HeaderText = L"Name";
			this->NameClient->MinimumWidth = 4;
			this->NameClient->Name = L"NameClient";
			this->NameClient->ReadOnly = true;
			this->NameClient->Width = 200;
			// 
			// PhoneClient
			// 
			this->PhoneClient->FillWeight = 35.08772F;
			this->PhoneClient->HeaderText = L"Phone";
			this->PhoneClient->MinimumWidth = 4;
			this->PhoneClient->Name = L"PhoneClient";
			this->PhoneClient->ReadOnly = true;
			// 
			// EmailClient
			// 
			this->EmailClient->FillWeight = 35.08772F;
			this->EmailClient->HeaderText = L"Email";
			this->EmailClient->MinimumWidth = 4;
			this->EmailClient->Name = L"EmailClient";
			this->EmailClient->ReadOnly = true;
			// 
			// CityClient
			// 
			this->CityClient->FillWeight = 35.08772F;
			this->CityClient->HeaderText = L"City";
			this->CityClient->MinimumWidth = 4;
			this->CityClient->Name = L"CityClient";
			this->CityClient->ReadOnly = true;
			// 
			// LoctionClient
			// 
			this->LoctionClient->FillWeight = 35.08772F;
			this->LoctionClient->HeaderText = L"Loction";
			this->LoctionClient->MinimumWidth = 4;
			this->LoctionClient->Name = L"LoctionClient";
			this->LoctionClient->ReadOnly = true;
			// 
			// editClient
			// 
			this->editClient->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->editClient->FillWeight = 50;
			this->editClient->HeaderText = L"";
			this->editClient->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editClient.Image")));
			this->editClient->MinimumWidth = 50;
			this->editClient->Name = L"editClient";
			this->editClient->ReadOnly = true;
			this->editClient->Width = 50;
			// 
			// delClient
			// 
			this->delClient->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->delClient->FillWeight = 50;
			this->delClient->HeaderText = L"";
			this->delClient->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delClient.Image")));
			this->delClient->MinimumWidth = 50;
			this->delClient->Name = L"delClient";
			this->delClient->ReadOnly = true;
			this->delClient->Width = 50;
			// 
			// panel16
			// 
			this->panel16->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel16->Location = System::Drawing::Point(44, 619);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(858, 43);
			this->panel16->TabIndex = 1;
			// 
			// panel15
			// 
			this->panel15->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel15->Location = System::Drawing::Point(902, 170);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(51, 492);
			this->panel15->TabIndex = 1;
			// 
			// panel14
			// 
			this->panel14->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel14->Location = System::Drawing::Point(0, 170);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(44, 492);
			this->panel14->TabIndex = 1;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->lbClient);
			this->panel12->Controls->Add(this->label10);
			this->panel12->Controls->Add(this->label9);
			this->panel12->Controls->Add(this->panel13);
			this->panel12->Controls->Add(this->btnAddClient);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel12->Location = System::Drawing::Point(0, 0);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(953, 170);
			this->panel12->TabIndex = 0;
			// 
			// lbClient
			// 
			this->lbClient->AutoSize = true;
			this->lbClient->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbClient->Location = System::Drawing::Point(38, 16);
			this->lbClient->Name = L"lbClient";
			this->lbClient->Size = System::Drawing::Size(83, 31);
			this->lbClient->TabIndex = 10;
			this->lbClient->Text = L"Clients";
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label10->Location = System::Drawing::Point(704, 54);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(112, 28);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Add Clients";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label9->Location = System::Drawing::Point(42, 63);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 28);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Search";
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::Transparent;
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel13->Controls->Add(this->pictureBox11);
			this->panel13->Controls->Add(this->textBox2);
			this->panel13->Location = System::Drawing::Point(44, 94);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(325, 39);
			this->panel13->TabIndex = 8;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(-1, 0);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(36, 34);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox11->TabIndex = 5;
			this->pictureBox11->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox2->Location = System::Drawing::Point(31, 0);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(292, 37);
			this->textBox2->TabIndex = 4;
			// 
			// btnAddClient
			// 
			this->btnAddClient->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddClient->BackColor = System::Drawing::Color::Red;
			this->btnAddClient->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAddClient->FlatAppearance->BorderSize = 0;
			this->btnAddClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddClient->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btnAddClient->ForeColor = System::Drawing::Color::Transparent;
			this->btnAddClient->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddClient.Image")));
			this->btnAddClient->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddClient->Location = System::Drawing::Point(709, 86);
			this->btnAddClient->Name = L"btnAddClient";
			this->btnAddClient->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btnAddClient->Size = System::Drawing::Size(193, 45);
			this->btnAddClient->TabIndex = 7;
			this->btnAddClient->Text = L"Add";
			this->btnAddClient->UseVisualStyleBackColor = false;
			this->btnAddClient->Click += gcnew System::EventHandler(this, &MyForm::btnAddClient_Click);
			// 
			// pn_item
			// 
			this->pn_item->Controls->Add(this->dataProduct);
			this->pn_item->Controls->Add(this->panel21);
			this->pn_item->Controls->Add(this->panel20);
			this->pn_item->Controls->Add(this->panel8);
			this->pn_item->Controls->Add(this->panel19);
			this->pn_item->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_item->Location = System::Drawing::Point(0, 0);
			this->pn_item->Name = L"pn_item";
			this->pn_item->Size = System::Drawing::Size(953, 662);
			this->pn_item->TabIndex = 6;
			// 
			// dataProduct
			// 
			this->dataProduct->AllowUserToAddRows = false;
			this->dataProduct->AllowUserToDeleteRows = false;
			dataGridViewCellStyle27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataProduct->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle27;
			this->dataProduct->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataProduct->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataProduct->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataProduct->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataProduct->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedHorizontal;
			this->dataProduct->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->dataProduct->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle28->BackColor = System::Drawing::Color::Red;
			dataGridViewCellStyle28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle28->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle28->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle28->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle28->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataProduct->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle28;
			this->dataProduct->ColumnHeadersHeight = 40;
			this->dataProduct->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->idProducts,
					this->nameProduct, this->Photo, this->BuyingPrice, this->QTY, this->SellingPrice, this->DiscountedPrice, this->CategoryName,
					this->editProduct, this->delProduct
			});
			dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle31->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle31->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle31->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle31->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataProduct->DefaultCellStyle = dataGridViewCellStyle31;
			this->dataProduct->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataProduct->EnableHeadersVisualStyles = false;
			this->dataProduct->GridColor = System::Drawing::SystemColors::GrayText;
			this->dataProduct->Location = System::Drawing::Point(23, 164);
			this->dataProduct->Name = L"dataProduct";
			this->dataProduct->ReadOnly = true;
			dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle32->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle32->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle32->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle32->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataProduct->RowHeadersDefaultCellStyle = dataGridViewCellStyle32;
			this->dataProduct->RowHeadersVisible = false;
			this->dataProduct->RowHeadersWidth = 10;
			this->dataProduct->RowTemplate->Height = 40;
			this->dataProduct->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataProduct->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataProduct->Size = System::Drawing::Size(905, 458);
			this->dataProduct->TabIndex = 5;
			this->dataProduct->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataProduct_CellContentClick);
			// 
			// idProducts
			// 
			this->idProducts->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->idProducts->DefaultCellStyle = dataGridViewCellStyle29;
			this->idProducts->FillWeight = 50;
			this->idProducts->HeaderText = L"ID";
			this->idProducts->MinimumWidth = 2;
			this->idProducts->Name = L"idProducts";
			this->idProducts->ReadOnly = true;
			this->idProducts->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->idProducts->Width = 40;
			// 
			// nameProduct
			// 
			this->nameProduct->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->nameProduct->DefaultCellStyle = dataGridViewCellStyle30;
			this->nameProduct->FillWeight = 200;
			this->nameProduct->HeaderText = L"Product";
			this->nameProduct->MinimumWidth = 6;
			this->nameProduct->Name = L"nameProduct";
			this->nameProduct->ReadOnly = true;
			// 
			// Photo
			// 
			this->Photo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Photo->FillWeight = 10;
			this->Photo->HeaderText = L"Photo";
			this->Photo->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Photo->MinimumWidth = 3;
			this->Photo->Name = L"Photo";
			this->Photo->ReadOnly = true;
			this->Photo->Width = 60;
			// 
			// BuyingPrice
			// 
			this->BuyingPrice->FillWeight = 60;
			this->BuyingPrice->HeaderText = L"Buying";
			this->BuyingPrice->MinimumWidth = 6;
			this->BuyingPrice->Name = L"BuyingPrice";
			this->BuyingPrice->ReadOnly = true;
			this->BuyingPrice->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->BuyingPrice->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// QTY
			// 
			this->QTY->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->QTY->FillWeight = 60;
			this->QTY->HeaderText = L"QTY";
			this->QTY->MinimumWidth = 6;
			this->QTY->Name = L"QTY";
			this->QTY->ReadOnly = true;
			this->QTY->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->QTY->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->QTY->Width = 60;
			// 
			// SellingPrice
			// 
			this->SellingPrice->FillWeight = 60;
			this->SellingPrice->HeaderText = L"Selling";
			this->SellingPrice->MinimumWidth = 6;
			this->SellingPrice->Name = L"SellingPrice";
			this->SellingPrice->ReadOnly = true;
			this->SellingPrice->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->SellingPrice->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// DiscountedPrice
			// 
			this->DiscountedPrice->HeaderText = L"Discounted";
			this->DiscountedPrice->MinimumWidth = 6;
			this->DiscountedPrice->Name = L"DiscountedPrice";
			this->DiscountedPrice->ReadOnly = true;
			// 
			// CategoryName
			// 
			this->CategoryName->HeaderText = L"Category";
			this->CategoryName->MinimumWidth = 6;
			this->CategoryName->Name = L"CategoryName";
			this->CategoryName->ReadOnly = true;
			// 
			// editProduct
			// 
			this->editProduct->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->editProduct->FillWeight = 30;
			this->editProduct->HeaderText = L"";
			this->editProduct->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editProduct.Image")));
			this->editProduct->MinimumWidth = 30;
			this->editProduct->Name = L"editProduct";
			this->editProduct->ReadOnly = true;
			this->editProduct->Width = 30;
			// 
			// delProduct
			// 
			this->delProduct->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->delProduct->FillWeight = 30;
			this->delProduct->HeaderText = L"";
			this->delProduct->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delProduct.Image")));
			this->delProduct->MinimumWidth = 30;
			this->delProduct->Name = L"delProduct";
			this->delProduct->ReadOnly = true;
			this->delProduct->Width = 30;
			// 
			// panel21
			// 
			this->panel21->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel21->Location = System::Drawing::Point(23, 622);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(905, 40);
			this->panel21->TabIndex = 8;
			// 
			// panel20
			// 
			this->panel20->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel20->Location = System::Drawing::Point(928, 164);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(25, 498);
			this->panel20->TabIndex = 7;
			// 
			// panel8
			// 
			this->panel8->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel8->Location = System::Drawing::Point(0, 164);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(23, 498);
			this->panel8->TabIndex = 6;
			// 
			// panel19
			// 
			this->panel19->Controls->Add(this->pictureBox10);
			this->panel19->Controls->Add(this->label13);
			this->panel19->Controls->Add(this->panel18);
			this->panel19->Controls->Add(this->searchProducts);
			this->panel19->Controls->Add(this->label15);
			this->panel19->Controls->Add(this->label16);
			this->panel19->Controls->Add(this->btnAddProductMain);
			this->panel19->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel19->Location = System::Drawing::Point(0, 0);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(953, 164);
			this->panel19->TabIndex = 4;
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(44, 107);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(32, 27);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox10->TabIndex = 5;
			this->pictureBox10->TabStop = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label13->Location = System::Drawing::Point(48, 76);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(70, 28);
			this->label13->TabIndex = 20;
			this->label13->Text = L"Search";
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::Red;
			this->panel18->Location = System::Drawing::Point(53, 144);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(370, 3);
			this->panel18->TabIndex = 19;
			// 
			// searchProducts
			// 
			this->searchProducts->BackColor = System::Drawing::Color::White;
			this->searchProducts->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->searchProducts->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchProducts->ForeColor = System::Drawing::Color::Black;
			this->searchProducts->Location = System::Drawing::Point(86, 117);
			this->searchProducts->Multiline = true;
			this->searchProducts->Name = L"searchProducts";
			this->searchProducts->Size = System::Drawing::Size(334, 40);
			this->searchProducts->TabIndex = 18;
			this->searchProducts->TextChanged += gcnew System::EventHandler(this, &MyForm::searchProducts_TextChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(38, 16);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(106, 31);
			this->label15->TabIndex = 13;
			this->label15->Text = L"Products";
			// 
			// label16
			// 
			this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
			this->label16->Location = System::Drawing::Point(710, 77);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(131, 28);
			this->label16->TabIndex = 14;
			this->label16->Text = L"Add Products";
			// 
			// btnAddProductMain
			// 
			this->btnAddProductMain->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddProductMain->BackColor = System::Drawing::Color::Red;
			this->btnAddProductMain->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAddProductMain->FlatAppearance->BorderSize = 0;
			this->btnAddProductMain->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddProductMain->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btnAddProductMain->ForeColor = System::Drawing::Color::Transparent;
			this->btnAddProductMain->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddProductMain.Image")));
			this->btnAddProductMain->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddProductMain->Location = System::Drawing::Point(715, 109);
			this->btnAddProductMain->Name = L"btnAddProductMain";
			this->btnAddProductMain->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btnAddProductMain->Size = System::Drawing::Size(193, 45);
			this->btnAddProductMain->TabIndex = 11;
			this->btnAddProductMain->Text = L"Add";
			this->btnAddProductMain->UseVisualStyleBackColor = false;
			this->btnAddProductMain->Click += gcnew System::EventHandler(this, &MyForm::btnAddProductMain_Click);
			// 
			// pn_home
			// 
			this->pn_home->Controls->Add(this->flowLayoutPanel1);
			this->pn_home->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_home->Location = System::Drawing::Point(0, 0);
			this->pn_home->Name = L"pn_home";
			this->pn_home->Size = System::Drawing::Size(953, 662);
			this->pn_home->TabIndex = 3;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Controls->Add(this->panel3);
			this->flowLayoutPanel1->Controls->Add(this->panel5);
			this->flowLayoutPanel1->Controls->Add(this->panel6);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(953, 540);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->panel1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(277, 158);
			this->panel1->TabIndex = 4;
			this->panel1->UseWaitCursor = true;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(31, 59);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(67, 66);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(140, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 59);
			this->label2->TabIndex = 1;
			this->label2->Text = L"100";
			this->label2->UseWaitCursor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(27, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sales Count";
			this->label1->UseWaitCursor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(277, 158);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->UseWaitCursor = true;
			// 
			// panel3
			// 
			this->panel3->AutoScroll = true;
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->Controls->Add(this->pictureBox4);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->pictureBox5);
			this->panel3->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->panel3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->panel3->Location = System::Drawing::Point(283, 2);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(277, 158);
			this->panel3->TabIndex = 5;
			this->panel3->UseWaitCursor = true;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(31, 59);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(67, 66);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->UseWaitCursor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(140, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 59);
			this->label3->TabIndex = 1;
			this->label3->Text = L"100";
			this->label3->UseWaitCursor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(27, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 23);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Sales Count";
			this->label4->UseWaitCursor = true;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(0, 0);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(277, 158);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 0;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->UseWaitCursor = true;
			// 
			// panel5
			// 
			this->panel5->AutoScroll = true;
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->Controls->Add(this->pictureBox6);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->label6);
			this->panel5->Controls->Add(this->pictureBox7);
			this->panel5->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->panel5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->panel5->Location = System::Drawing::Point(564, 2);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(277, 158);
			this->panel5->TabIndex = 6;
			this->panel5->UseWaitCursor = true;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(31, 59);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(67, 66);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 2;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->UseWaitCursor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(140, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 59);
			this->label5->TabIndex = 1;
			this->label5->Text = L"100";
			this->label5->UseWaitCursor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(27, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 23);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Sales Count";
			this->label6->UseWaitCursor = true;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->pictureBox7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(0, 0);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(277, 158);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 0;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->UseWaitCursor = true;
			// 
			// panel6
			// 
			this->panel6->AutoScroll = true;
			this->panel6->BackColor = System::Drawing::Color::Transparent;
			this->panel6->Controls->Add(this->pictureBox8);
			this->panel6->Controls->Add(this->label7);
			this->panel6->Controls->Add(this->label8);
			this->panel6->Controls->Add(this->pictureBox9);
			this->panel6->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->panel6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->panel6->Location = System::Drawing::Point(2, 164);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(277, 158);
			this->panel6->TabIndex = 7;
			this->panel6->UseWaitCursor = true;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(31, 59);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(67, 66);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 2;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->UseWaitCursor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(140, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 59);
			this->label7->TabIndex = 1;
			this->label7->Text = L"100";
			this->label7->UseWaitCursor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(27, 22);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(100, 23);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Sales Count";
			this->label8->UseWaitCursor = true;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(0, 0);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(277, 158);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 0;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->UseWaitCursor = true;
			// 
			// pn_orders
			// 
			this->pn_orders->Controls->Add(this->button4);
			this->pn_orders->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pn_orders->Location = System::Drawing::Point(0, 0);
			this->pn_orders->Name = L"pn_orders";
			this->pn_orders->Size = System::Drawing::Size(953, 662);
			this->pn_orders->TabIndex = 8;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(238, 546);
			this->button4->Name = L"button4";
			this->button4->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->button4->Size = System::Drawing::Size(220, 52);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Orders";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::btn_order_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1186, 721);
			this->Controls->Add(this->pn_main);
			this->Controls->Add(this->pn_title);
			this->Controls->Add(this->pn_nav);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->pn_title->ResumeLayout(false);
			this->pn_nav->ResumeLayout(false);
			this->flow_das->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->pn_main->ResumeLayout(false);
			this->pn_invoice->ResumeLayout(false);
			this->panel26->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataInv))->EndInit();
			this->panel27->ResumeLayout(false);
			this->panel27->PerformLayout();
			this->panel28->ResumeLayout(false);
			this->panel28->PerformLayout();
			this->panel30->ResumeLayout(false);
			this->panel30->PerformLayout();
			this->panel22->ResumeLayout(false);
			this->panel22->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			this->panel24->ResumeLayout(false);
			this->pn_admin->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataAdmin))->EndInit();
			this->panel37->ResumeLayout(false);
			this->panel35->ResumeLayout(false);
			this->panel35->PerformLayout();
			this->pn_opex->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataOpex))->EndInit();
			this->panel29->ResumeLayout(false);
			this->panel29->PerformLayout();
			this->pn_cat->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_cat))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			this->pn_client->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataClient))->EndInit();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			this->pn_item->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataProduct))->EndInit();
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			this->pn_home->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->pn_orders->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = FormWindowState::Minimized;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == FormWindowState::Maximized)
		{
			this->WindowState = FormWindowState::Normal;
		}
		else this->WindowState = FormWindowState::Maximized;
	}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {

	}
	//private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	//}

	//cLose 
	private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
		Environment::Exit(0);

	}
	private: System::Void close_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		close->BackColor = Color::Red;


	}
	private: System::Void close_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		close->BackColor = Color::White;

	}

	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pn_home_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pn_opex_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btn_home_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_home->BringToFront();
	}
	private: System::Void btn_invoices_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_invoice->BringToFront();
	}
	private: System::Void btn_Client_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_client->BringToFront();
	}
	private: System::Void btn_items_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_item->BringToFront();
	}

	private: System::Void btn_order_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_orders->BringToFront();
	}


	private: System::Void btn_opex_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_opex->BringToFront();
	};
	private: System::Void btn_admin_Click(System::Object^ sender, System::EventArgs^ e) {
		pn_admin->BringToFront();
	}
	private: System::Void pn_admin_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void btn_home_Click_1(System::Object^ sender, System::EventArgs^ e) {
	pn_home->BringToFront();

}
private: System::Void pn_home_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void flowLayoutPanel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void btn_opex_Click_1(System::Object^ sender, System::EventArgs^ e) {
	pn_opex->BringToFront();


}
private: System::Void btn_cat_Click(System::Object^ sender, System::EventArgs^ e) {
	pn_cat->BringToFront();
}
private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void btn_zoom_Click(System::Object^ sender, System::EventArgs^ e) {
	if(pn_nav->Width==223)
	{
		pn_nav->Width = 85;
	}
}

private: System::Void panel2_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}

private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void pn_cat_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}



private: System::Void panel10_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel14_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void dataClient_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return;

	// When clicking the Edit button, the Edit form will appear
	int editColumnIndex = dataClient->Columns["editClient"]->Index; // Edit column
	// When clicking the Delete button, the Delete confirmation will appear
	int deleteColumnIndex = dataClient->Columns["delClient"]->Index; // Delete column

	if (e->ColumnIndex == editColumnIndex) {
		// Show the Edit form
		DataGridViewRow^ row = dataClient->Rows[e->RowIndex];
		String^ id = row->Cells["dataGridViewTextBoxColumn1"]->Value->ToString(); // ID
		String^ name = row->Cells["NameClient"]->Value->ToString(); // Name
		String^ phone = row->Cells["PhoneClient"]->Value->ToString(); // Phone
		String^ email = row->Cells["EmailClient"]->Value->ToString(); // Email
		String^ city = row->Cells["CityClient"]->Value->ToString(); // City
		String^ location = row->Cells["LoctionClient"]->Value->ToString(); // Location

		AddClients^ editClientForm = gcnew AddClients(dataClient, editImg, delImg);
		editClientForm->SetClientData(id, name, phone, email, city, location); // Assume SetClientData exists in AddClients form
		editClientForm->Show();
	}
	else if (e->ColumnIndex == deleteColumnIndex) {
		String^ id = dataClient->Rows[e->RowIndex]->Cells["dataGridViewTextBoxColumn1"]->Value->ToString();
		String^ name = dataClient->Rows[e->RowIndex]->Cells["NameClient"]->Value->ToString();
		// Ask for confirmation to delete the client
		if (MessageBox::Show("Do you want to delete the " + name + "?", "Are you sure?", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			SqlConnection^ conn = Database::GetCon();
			String^ query = "DELETE FROM clients WHERE ID = @id";

			try {
				conn->Open();
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@id", id);
				cmd->ExecuteNonQuery();
				conn->Close();

				dataClient->Rows->Clear();
				ClientController::LoadClients(dataClient, editImg, delImg);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Database error: " + ex->Message);
			}
		}
	}
}private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnAddCat_Click(System::Object^ sender, System::EventArgs^ e) {
	AddCat^ addCat = gcnew AddCat(data_cat,editImg,delImg);
	addCat->Show();
}
private: System::Void btnAddClient_Click(System::Object^ sender, System::EventArgs^ e) {
	AddClients^ addClient = gcnew AddClients(dataClient, editImg, delImg);
	addClient->Show();
}

 
private: System::Void data_cat_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0)return;
	//بمجرد ما هيدوس على زر الـ Edit هيظهر الفورم الخاص بالـ Edit
	int editColumnIndex = data_cat->Columns["edit"]->Index; // عمود الـ Edit
	//بمجرد ما هيدوس على زر الـ Delete هيظهر الفورم الخاص بالـ Delete
	int deleteColumnIndex = data_cat->Columns["del"]->Index; // عمود الـ Delete


	if (e->ColumnIndex == editColumnIndex) {
		// هنا هتظهر الفورم الخاصة بالـ Edit
		DataGridViewRow^ row = data_cat->Rows[e->RowIndex];
		String^ id = row->Cells["ID_Cat"]->Value->ToString(); // الـ ID
		String^ name = row->Cells["name_Cat"]->Value->ToString(); // الاسم


		AddCat^ addCat = gcnew AddCat(data_cat, editImg, delImg);
		addCat->SetCatData(id, name); // افترض إن في دالة SetClientData في فورم AddClients
		addCat->Show();
	}
	else if (e->ColumnIndex == deleteColumnIndex) {
		String^ id = data_cat->Rows[e->RowIndex]->Cells["ID_Cat"]->Value->ToString();
		String^ name = data_cat->Rows[e->RowIndex]->Cells["name_Cat"]->Value->ToString();

		//do you want to delete the client
		// ارسال اسم cat
		
		if (MessageBox::Show("Do you want to delete the "+name+"?", " Are you Sure ", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			SqlConnection^ conn = Database::GetCon();
			String^ query = "DELETE FROM Categories WHERE ID = @id";

			try {
				conn->Open();
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@id", id);
				cmd->ExecuteNonQuery();
				conn->Close();

				data_cat->Rows->Clear();
				ClientController::LoadCat(data_cat, editImg, delImg);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error In Database: " + ex->Message);
			}
		}
	}
}


private: System::Void SearchCat_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox12_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void searchProducts_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	ClientController::LoadProducts(dataProduct, editImg, delImg, searchProducts->Text);
}
private: System::Void btnAddProductMain_Click(System::Object^ sender, System::EventArgs^ e) {
	AddProducts^ addProduct = gcnew AddProducts(dataProduct, editImg, delImg, flowLayoutPanel2);
	addProduct->Show();
}
private: System::Void dataProduct_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return; // Ignore clicks on headers

	int editColumnIndex = dataProduct->Columns["editProduct"]->Index; // Edit column
	int deleteColumnIndex = dataProduct->Columns["delProduct"]->Index; // Delete column

	if (e->ColumnIndex == editColumnIndex) {
		DataGridViewRow^ row = dataProduct->Rows[e->RowIndex];

		String^ id = row->Cells["idProducts"]->Value != nullptr ? row->Cells["idProducts"]->Value->ToString() : "0";
		String^ name = row->Cells["nameProduct"]->Value != nullptr ? row->Cells["nameProduct"]->Value->ToString() : "";
		String^ buyingPrice = row->Cells["BuyingPrice"]->Value != nullptr ? row->Cells["BuyingPrice"]->Value->ToString() : "0";
		String^ quantity = row->Cells["QTY"]->Value != nullptr ? row->Cells["QTY"]->Value->ToString() : "0";
		String^ sellingPrice = row->Cells["SellingPrice"]->Value != nullptr ? row->Cells["SellingPrice"]->Value->ToString() : "0";
		String^ discountedPrice = row->Cells["DiscountedPrice"]->Value != nullptr ? row->Cells["DiscountedPrice"]->Value->ToString() : "0";
		String^ category = row->Cells["CategoryName"]->Value != nullptr ? row->Cells["CategoryName"]->Value->ToString() : "";

		// التعامل مع العمود Photo
		String^ photoPath = "";
		if (row->Cells["Photo"]->Value != nullptr) {
			// لو القيمة هي Bitmap^، نحفظها كملف مؤقت
			if (row->Cells["Photo"]->Value->GetType() == Bitmap::typeid) {
				Bitmap^ bitmap = safe_cast<Bitmap^>(row->Cells["Photo"]->Value);
				String^ tempPath = System::IO::Path::Combine(System::IO::Path::GetTempPath(), "product_" + id + ".png");
				try {
					bitmap->Save(tempPath, System::Drawing::Imaging::ImageFormat::Png);
					photoPath = tempPath; // المسار المؤقت للصورة بصيغة PNG
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error saving image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					photoPath = "";
				}
			}
			else {
				// لو القيمة هي String^ (مسار)، نستخدمها مباشرة
				photoPath = row->Cells["Photo"]->Value->ToString();
				// تأكد إن المسار بصيغة PNG
			
			}
		}

		// تشخيص للتأكد من قيمة photoPath
		if (!String::IsNullOrEmpty(photoPath)) {
		}
		else {
			MessageBox::Show("No photo path found for this product.", "Debug Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		AddProducts^ addProduct = gcnew AddProducts(dataProduct, editImg, delImg, flowLayoutPanel2);
		addProduct->SetProductData(id, name, photoPath, buyingPrice, quantity, sellingPrice, discountedPrice, category);
		addProduct->Show();
	}
	else if (e->ColumnIndex == deleteColumnIndex) {
		String^ id = dataProduct->Rows[e->RowIndex]->Cells["idProducts"]->Value != nullptr ?
			dataProduct->Rows[e->RowIndex]->Cells["idProducts"]->Value->ToString() : "0";
		String^ name = dataProduct->Rows[e->RowIndex]->Cells["nameProduct"]->Value != nullptr ?
			dataProduct->Rows[e->RowIndex]->Cells["nameProduct"]->Value->ToString() : "Unknown";

		if (MessageBox::Show("Do you want to delete the product '" + name + "'?", "Are you sure?",
			MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			SqlConnection^ conn = Database::GetCon();
			String^ query = "DELETE FROM Product WHERE ProductID = @id";
			try {
				conn->Open();
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				int productIdValue = 0;
				if (!Int32::TryParse(id, productIdValue)) {
					MessageBox::Show("Invalid product ID!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				cmd->Parameters->AddWithValue("@id", productIdValue);

				int rowsAffected = cmd->ExecuteNonQuery();
				if (rowsAffected > 0) {
					MessageBox::Show("Product deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					ClientController::LoadProducts(dataProduct, editImg, delImg, "");
					// هنا هضيف كرت 
					ClientController::LoadProductCards(flowLayoutPanel2, "");

				}
				else {
					MessageBox::Show("Failed to delete product!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			catch (SqlException^ sqlEx) {
				MessageBox::Show("Database error: " + sqlEx->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (conn->State == ConnectionState::Open) {
					conn->Close();
					delete conn;
				}
			}
		}
	}
}private: System::Void nameCard_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addInv_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void panel23_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void btn_newCat_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void comboCategory_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataInv_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// بنتأكد إن المستخدم ضغط على خلية مش راس الجدول
	if (e->RowIndex >= 0) {
		if (dataInv->Columns->Contains("delInv") && e->ColumnIndex == dataInv->Columns["delInv"]->Index) {
			try {
				// بنتأكد إن خلية ProductName موجودة وفيها قيمة
				String^ productName = "Unknown Product";
				if (dataInv->Columns->Contains("ProductName") &&
					dataInv->Rows[e->RowIndex]->Cells["ProductName"]->Value != nullptr) {
					productName = dataInv->Rows[e->RowIndex]->Cells["ProductName"]->Value->ToString();
				}
				else {
					// لو ProductName مش موجود، بنستخدم قيمة افتراضية
			
				}

				// بنسأل المستخدم لو عايز يحذف الصف
				if (MessageBox::Show("Are you sure you want to delete " + productName + " from the invoice?",
					"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== System::Windows::Forms::DialogResult::Yes) {

					// بنشيل الصف من الـ DataGridView
					dataInv->Rows->RemoveAt(e->RowIndex);

					// بنحدّث الإجمالي وبنحطه في الـ Label
					if (lblTotalSum != nullptr) {
						lblTotalSum->Text = String::Format("{0:F2} EGP", CalculateTotalSum());
					}
					else {
						MessageBox::Show("lblTotalSum is not initialized!", "Error",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
					}

					// بنطلّع رسالة نجاح
					MessageBox::Show("Product deleted successfully!", "Success",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				// لو حصل أي خطأ، بنطلّع رسالة واضحة
				MessageBox::Show("Error deleting product: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			// لو العمود مش DeleteButton، بنطلّع رسالة ديباج
			MessageBox::Show("Clicked column is not DeleteButton. Column Index: " + e->ColumnIndex, "Debug",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
}private: System::Void dellAll(System::Object^ sender, System::EventArgs^ e) {
	dataInv->Rows->Clear();
	lblTotalSum->Text = "0.00";

	
}
private: System::Void label19_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label18_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel28_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void AddOpex_Click(System::Object^ sender, System::EventArgs^ e) {

	AddOpex1^ addOpex = gcnew AddOpex1(dataOpex);
	addOpex->Show();
}
private: System::Void AddAdimMain_Click(System::Object^ sender, System::EventArgs^ e) {
	AddAdmin^ addadmin = gcnew AddAdmin(dataAdmin);
	addadmin->Show();

}
private: System::Void dataAdmin_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex == dataAdmin->Columns["DelUser"]->Index && e->RowIndex >= 0) {
		try {
			Object^ idValue = dataAdmin->Rows[e->RowIndex]->Cells["IdAdimin"]->Value;
			if (idValue == nullptr || String::IsNullOrEmpty(idValue->ToString())) {
				MessageBox::Show("Invalid admin ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			int id;
			if (!Int32::TryParse(idValue->ToString(), id)) {
				MessageBox::Show("Admin ID is not a valid number.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Confirm deletion
			if (MessageBox::Show("Are you sure you want to delete admin with ID " + id + "?", "Confirm Delete",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				// Get database connection
				SqlConnection^ con = Database::GetCon();
				String^ query = "DELETE FROM users WHERE ID = @ID";
				SqlCommand^ cmd = gcnew SqlCommand(query, con);

				cmd->Parameters->AddWithValue("@ID", id);

				con->Open();
				int rowsAffected = cmd->ExecuteNonQuery();

				if (rowsAffected > 0) {
					dataAdmin->Rows->RemoveAt(e->RowIndex);

					MessageBox::Show("Admin deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("No admin was deleted. ID not found.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
		catch (SqlException^ ex) {
			if (ex->Number == 547) { 
				MessageBox::Show("Cannot delete admin because it is referenced elsewhere.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				MessageBox::Show("Database error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error deleting admin: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
		}
	}

private: System::Void dataInv_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		// بنتأكد إن العمود موجود وإنه DeleteButton
		if (dataInv->Columns->Contains("DelInv") && e->ColumnIndex == dataInv->Columns["DelInv"]->Index) {
			try {
				// بنتأكد إن خلية ProductName موجودة وفيها قيمة
				String^ productName = "Unknown Product";
				if (dataInv->Columns->Contains("ProductName") &&
					dataInv->Rows[e->RowIndex]->Cells["ProductName"]->Value != nullptr) {
					productName = dataInv->Rows[e->RowIndex]->Cells["ProductName"]->Value->ToString();
				}
				else {
					// لو ProductName مش موجود، بنستخدم قيمة افتراضية
			
				}

				// بنسأل المستخدم لو عايز يحذف الصف
				if (MessageBox::Show("Are you sure you want to delete " + productName + " from the invoice?",
					"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== System::Windows::Forms::DialogResult::Yes) {

					// بنشيل الصف من الـ DataGridView
					dataInv->Rows->RemoveAt(e->RowIndex);

					// بنحدّث الإجمالي وبنحطه في الـ Label
					if (lblTotalSum != nullptr) {
						lblTotalSum->Text = String::Format("{0:F2} EGP", CalculateTotalSum());
					}
					else {
						MessageBox::Show("lblTotalSum is not initialized!", "Error",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
					}

					// بنطلّع رسالة نجاح
					MessageBox::Show("Product deleted successfully!", "Success",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				// لو حصل أي خطأ، بنطلّع رسالة واضحة
				MessageBox::Show("Error deleting product: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			// لو العمود مش DeleteButton، بنطلّع رسالة ديباج
			MessageBox::Show("Clicked column is not DeleteButton. Column Index: " + e->ColumnIndex, "Debug",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
}
private: System::Void btnPrint_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// إعداد PrintDocument
		pd = gcnew PrintDocument();
		pd->PrinterSettings->PrinterName = "Microsoft Print to PDF";

		// ضبط القياس لـ 80 مم (320 pixels عند 96 DPI)
		pd->DefaultPageSettings->PaperSize = gcnew PaperSize("Custom", 320, 1000); // الطول ديناميكي لاحقاً
		pd->DefaultPageSettings->Margins = gcnew Margins(10, 10, 10, 10);

		// إعداد اسم الملف للحفظ
		String^ fileName = "Invoice_" + DateTime::Now.ToString("yyyyMMdd_HHmmss") + ".pdf";
		String^ path = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Desktop), fileName);
		pd->PrinterSettings->PrintToFile = true;
		pd->PrinterSettings->PrintFileName = path;

		// إعداد بيانات الطباعة
		printData = gcnew PrintData();
		printData->CurrentRowIndex = 0;

		// ربط الحدث  الطباعة
		pd->PrintPage += gcnew PrintPageEventHandler(this, &MyForm::pd_PrintPage);

		// طباعة المستند
		pd->Print();

		// فتح الملف بعد الطباعة
		MessageBox::Show("Invoice saved as PDF: " + path, "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		System::Diagnostics::Process::Start(path);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error generating PDF: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void pd_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
	try {
		// إعداد الرسم
		Graphics^ g = e->Graphics;
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 10);
		System::Drawing::Font^ titleFont = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);

		// إعداد الأعمدة
		array<String^>^ headers = { "Item", "QTY", "Price", "After Dis", "Total" };
		array<int>^ columnWidths = { 150, 40, 90, 90, 90 };
		float xPos = 10;
		float yPos = 10;

		// رسم العنوان						    
		g->DrawString("                                          Fexa Team ", titleFont, brush, xPos, yPos);
		yPos += 40;
		g->DrawString("Invoice", titleFont, brush, xPos, yPos);
		yPos += 20;

		// رسم التاريخ
		String^ date = DateTime::Now.ToString("yyyy-MM-dd ");
		g->DrawString("Date: " + date, font, brush, xPos, yPos);
		yPos += 20;

		// رسم رأس الجدول
		for (int i = 0; i < headers->Length; i++) {
			g->FillRectangle(Brushes::LightGray, xPos, yPos, (float)columnWidths[i], 20.0f);
			g->DrawRectangle(Pens::Black, xPos, yPos, (float)columnWidths[i], 20.0f);
			g->DrawString(headers[i], font, brush, xPos + 5, yPos + 2);
			xPos += columnWidths[i];
		}
		yPos += 20;

		// رسم الصفوف
		while (printData->CurrentRowIndex < dataInv->Rows->Count) {
			DataGridViewRow^ row = dataInv->Rows[printData->CurrentRowIndex];
			if (!row->IsNewRow) {
				xPos = 10;
				for (int i = 0; i < columnWidths->Length; i++) {
					String^ cellValue = row->Cells[i]->Value != nullptr ?
						row->Cells[i]->Value->ToString() : "";
					g->FillRectangle(Brushes::White, xPos, yPos, (float)columnWidths[i], 20.0f);
					g->DrawRectangle(Pens::Black, xPos, yPos, (float)columnWidths[i], 20.0f);
					g->DrawString(cellValue, font, brush, xPos + 5, yPos + 2);
					xPos += columnWidths[i];
				}
				yPos += 20;
			}
			printData->CurrentRowIndex++;

			// لو وصلنا لآخر الصفحة، بنقول إن في صفحات تانية
			if (yPos > e->PageBounds.Height - 50) {
				e->HasMorePages = true;
				return;
			}
		}

		// رسم الإجمالي
		g->DrawString("Total: " + lblTotalSum->Text,
			gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold),
			brush, 310.0f, yPos + 20);

		// خلّصت الصفحات
		e->HasMorePages = false;
		printData->CurrentRowIndex = 0;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error printing page: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void btn_home_h(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button14_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}

};




}
