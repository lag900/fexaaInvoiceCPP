#pragma once
#include "Database.h"
#include "ClientController.h"
namespace Fexa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddCat
	/// </summary>
	public ref class AddCat : public System::Windows::Forms::Form
	{
	private: 
		DataGridView^ dataGridView;
		Image^ editImg;
		Image^ delImg;
		bool isEditMode = false; // تعديل النوع إلى bool
		String^ catId; // متغير جديد لتخزين الـ ID
	public:
		AddCat(DataGridView^ e,Image^ed, Image^fe)
		{
			InitializeComponent();
			dataGridView = e;
			editImg = ed;
			delImg = fe;
			//
			//TODO: Add the constructor code here
			//
		}

		void SetCatData(String^ id, String^ name)
		{
			catId = id;
			txtCat->Text = name;
			isEditMode = true;
			this->btn_newCat->Text = L"Update";
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddCat()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ closeAddCat;
	protected:

	private: System::Windows::Forms::Button^ btn_newCat;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private: System::Windows::Forms::TextBox^ txtCat;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label10;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddCat::typeid));
			this->closeAddCat = (gcnew System::Windows::Forms::Button());
			this->btn_newCat = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txtCat = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// closeAddCat
			// 
			this->closeAddCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->closeAddCat->BackColor = System::Drawing::Color::White;
			this->closeAddCat->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeAddCat.BackgroundImage")));
			this->closeAddCat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->closeAddCat->FlatAppearance->BorderSize = 0;
			this->closeAddCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeAddCat->ForeColor = System::Drawing::Color::Transparent;
			this->closeAddCat->Location = System::Drawing::Point(442, -6);
			this->closeAddCat->Margin = System::Windows::Forms::Padding(0);
			this->closeAddCat->Name = L"closeAddCat";
			this->closeAddCat->Size = System::Drawing::Size(68, 79);
			this->closeAddCat->TabIndex = 1;
			this->closeAddCat->UseVisualStyleBackColor = false;
			this->closeAddCat->Click += gcnew System::EventHandler(this, &AddCat::closeAddCat_Click);
			// 
			// btn_newCat
			// 
			this->btn_newCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_newCat->BackColor = System::Drawing::Color::White;
			this->btn_newCat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_newCat->FlatAppearance->BorderSize = 0;
			this->btn_newCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_newCat->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btn_newCat->ForeColor = System::Drawing::Color::Black;
			this->btn_newCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_newCat.Image")));
			this->btn_newCat->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_newCat->Location = System::Drawing::Point(144, 356);
			this->btn_newCat->Name = L"btn_newCat";
			this->btn_newCat->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btn_newCat->Size = System::Drawing::Size(222, 69);
			this->btn_newCat->TabIndex = 1;
			this->btn_newCat->Text = L"Add";
			this->btn_newCat->UseVisualStyleBackColor = false;
			this->btn_newCat->Click += gcnew System::EventHandler(this, &AddCat::btn_newCat_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->closeAddCat);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(510, 109);
			this->panel1->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16.2F, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(96, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 38);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Category ";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(14, 20);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(76, 68);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// txtCat
			// 
			this->txtCat->BackColor = System::Drawing::SystemColors::Control;
			this->txtCat->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCat->ForeColor = System::Drawing::Color::Black;
			this->txtCat->Location = System::Drawing::Point(83, 222);
			this->txtCat->Multiline = true;
			this->txtCat->Name = L"txtCat";
			this->txtCat->Size = System::Drawing::Size(345, 40);
			this->txtCat->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(86, 252);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(328, 3);
			this->panel2->TabIndex = 11;
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.8F));
			this->label10->Location = System::Drawing::Point(81, 176);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(56, 23);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Name";
			// 
			// AddCat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(510, 449);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->txtCat);
			this->Controls->Add(this->btn_newCat);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AddCat";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddCat";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void closeAddCat_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btn_newCat_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtCat->Text == "")
	{
		MessageBox::Show("Please enter a category name", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	
		SqlConnection^ con = Database::GetCon();

		String^ query  ;

	try {
		con->Open();
		if (isEditMode) {
			query = "UPDATE Categories SET category_name = @Name WHERE ID = @ID";
		}
		else {
			query = "INSERT INTO Categories (category_name) VALUES (@Name)";
		}

		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@Name", txtCat->Text);

		if (isEditMode) {
			cmd->Parameters->AddWithValue("@id", catId);
		}

		int rowsAffected = cmd->ExecuteNonQuery();
		if (rowsAffected > 0) {
			MessageBox::Show(isEditMode ? "Categories updated successfully!" : "Client added successfully!",
				"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			txtCat->Clear();
			dataGridView->Rows->Clear(); 
			ClientController::LoadCat(dataGridView, editImg, delImg);
			this->Close();
		}
		else {
			MessageBox::Show(isEditMode ? "Failed to update Categories!" : "Failed to add Categories!",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (SqlException^ sqlEx) {
		MessageBox::Show("Database error: " + sqlEx->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		if (con->State == ConnectionState::Open) {
			con->Close();
		}
	}



}
};
}