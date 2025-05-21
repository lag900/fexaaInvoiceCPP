#pragma once
#include "ClientController.h"
#include "Database.h"
namespace Fexa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for AddExop
	/// </summary>
	public ref class AddOpex1 : public System::Windows::Forms::Form
	{
      DataGridView^ dataGridView;

	public:
		AddOpex1(DataGridView^ dgv)
		{
			dataGridView = dgv;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddOpex1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ closeAddExpo;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ ProductName;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txtQty;

	private: System::Windows::Forms::TextBox^ txtPrice;

	private: System::Windows::Forms::TextBox^ txtProductName;
	private: System::Windows::Forms::Button^ btnAddOpex;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddOpex1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->closeAddExpo = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ProductName = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txtQty = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtProductName = (gcnew System::Windows::Forms::TextBox());
			this->btnAddOpex = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->closeAddExpo);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(623, 114);
			this->panel1->TabIndex = 0;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16.2F, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(106, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 38);
			this->label6->TabIndex = 19;
			this->label6->Text = L"OPEX";
			// 
			// closeAddExpo
			// 
			this->closeAddExpo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->closeAddExpo->BackColor = System::Drawing::Color::White;
			this->closeAddExpo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->closeAddExpo->FlatAppearance->BorderSize = 0;
			this->closeAddExpo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeAddExpo->ForeColor = System::Drawing::Color::Transparent;
			this->closeAddExpo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeAddExpo.Image")));
			this->closeAddExpo->Location = System::Drawing::Point(555, 0);
			this->closeAddExpo->Margin = System::Windows::Forms::Padding(0);
			this->closeAddExpo->Name = L"closeAddExpo";
			this->closeAddExpo->Size = System::Drawing::Size(68, 79);
			this->closeAddExpo->TabIndex = 2;
			this->closeAddExpo->UseVisualStyleBackColor = false;
			this->closeAddExpo->Click += gcnew System::EventHandler(this, &AddOpex1::closeAddExpo_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(24, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(76, 68);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label2->Location = System::Drawing::Point(15, 238);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 20);
			this->label2->TabIndex = 87;
			this->label2->Text = L"QTY";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label1->Location = System::Drawing::Point(258, 239);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 20);
			this->label1->TabIndex = 88;
			this->label1->Text = L"Price";
			// 
			// ProductName
			// 
			this->ProductName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ProductName->AutoSize = true;
			this->ProductName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->ProductName->Location = System::Drawing::Point(18, 158);
			this->ProductName->Name = L"ProductName";
			this->ProductName->Size = System::Drawing::Size(60, 20);
			this->ProductName->TabIndex = 89;
			this->ProductName->Text = L"Product";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(19, 292);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(132, 3);
			this->panel3->TabIndex = 82;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(261, 292);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(311, 3);
			this->panel6->TabIndex = 84;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(19, 219);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(567, 3);
			this->panel2->TabIndex = 85;
			// 
			// txtQty
			// 
			this->txtQty->BackColor = System::Drawing::SystemColors::Control;
			this->txtQty->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtQty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtQty->ForeColor = System::Drawing::Color::Black;
			this->txtQty->Location = System::Drawing::Point(16, 262);
			this->txtQty->Multiline = true;
			this->txtQty->Name = L"txtQty";
			this->txtQty->Size = System::Drawing::Size(149, 40);
			this->txtQty->TabIndex = 80;
			// 
			// txtPrice
			// 
			this->txtPrice->BackColor = System::Drawing::SystemColors::Control;
			this->txtPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPrice->ForeColor = System::Drawing::Color::Black;
			this->txtPrice->Location = System::Drawing::Point(258, 262);
			this->txtPrice->Multiline = true;
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(328, 40);
			this->txtPrice->TabIndex = 79;
			// 
			// txtProductName
			// 
			this->txtProductName->BackColor = System::Drawing::SystemColors::Control;
			this->txtProductName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtProductName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtProductName->ForeColor = System::Drawing::Color::Black;
			this->txtProductName->Location = System::Drawing::Point(24, 189);
			this->txtProductName->Multiline = true;
			this->txtProductName->Name = L"txtProductName";
			this->txtProductName->Size = System::Drawing::Size(584, 40);
			this->txtProductName->TabIndex = 78;
			// 
			// btnAddOpex
			// 
			this->btnAddOpex->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddOpex->BackColor = System::Drawing::Color::White;
			this->btnAddOpex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAddOpex->FlatAppearance->BorderSize = 0;
			this->btnAddOpex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddOpex->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btnAddOpex->ForeColor = System::Drawing::Color::Black;
			this->btnAddOpex->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddOpex.Image")));
			this->btnAddOpex->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddOpex->Location = System::Drawing::Point(195, 381);
			this->btnAddOpex->Name = L"btnAddOpex";
			this->btnAddOpex->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btnAddOpex->Size = System::Drawing::Size(222, 69);
			this->btnAddOpex->TabIndex = 90;
			this->btnAddOpex->Text = L"Add";
			this->btnAddOpex->UseVisualStyleBackColor = false;
			this->btnAddOpex->Click += gcnew System::EventHandler(this, &AddOpex1::btnAddOpex_Click);
			// 
			// AddOpex1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(623, 462);
			this->Controls->Add(this->btnAddOpex);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ProductName);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->txtQty);
			this->Controls->Add(this->txtPrice);
			this->Controls->Add(this->txtProductName);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AddOpex1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddExop";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void closeAddExpo_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnAddOpex_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtProductName->Text==""||txtPrice->Text==""||txtQty->Text=="")
		{
			MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int qty;
		Decimal price;
		if (!Int32::TryParse(txtQty->Text, qty) || !Decimal::TryParse(txtPrice->Text, price))
		{
			MessageBox::Show("Please enter valid values for quantity and price", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		SqlConnection^ con = Database::GetCon();

		try
		{
			con->Open();
			String^ query = "INSERT INTO Opex (ProductName, Price, Quantity) VALUES (@ProductName, @Price, @Quantity)";
			SqlCommand^ cmd = gcnew SqlCommand(query, con);
			cmd->Parameters->AddWithValue("@ProductName", txtProductName->Text);
			cmd->Parameters->AddWithValue("@Price", price);
			cmd->Parameters->AddWithValue("@Quantity", qty);
			cmd->ExecuteNonQuery();
			con->Close();
			txtPrice->Text = "";
			txtProductName->Text = "";
			txtQty->Text = "";
			MessageBox::Show("Opex added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
			ClientController::LoadOpex(dataGridView);




		}
		catch (Exception ^ ex)
		{
			MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	
	}
};
}
