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
	/// Summary for AddAdmin
	/// </summary>
	public ref class AddAdmin : public System::Windows::Forms::Form
	{
		DataGridView^ dataGridView;
	public:
		AddAdmin(DataGridView ^ dg)
		{
			dataGridView = dg;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ closeAddAdmin;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txtAddPass;

	private: System::Windows::Forms::TextBox^ txtAddUser;
	private: System::Windows::Forms::Button^ btnAddAdmin;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddAdmin::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->closeAddAdmin = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txtAddPass = (gcnew System::Windows::Forms::TextBox());
			this->txtAddUser = (gcnew System::Windows::Forms::TextBox());
			this->btnAddAdmin = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->closeAddAdmin);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(460, 112);
			this->panel1->TabIndex = 0;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16.2F, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(94, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 38);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Admin";
			this->label6->Click += gcnew System::EventHandler(this, &AddAdmin::label6_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(76, 68);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// closeAddAdmin
			// 
			this->closeAddAdmin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->closeAddAdmin->BackColor = System::Drawing::Color::White;
			this->closeAddAdmin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeAddAdmin.BackgroundImage")));
			this->closeAddAdmin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->closeAddAdmin->FlatAppearance->BorderSize = 0;
			this->closeAddAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeAddAdmin->ForeColor = System::Drawing::Color::Transparent;
			this->closeAddAdmin->Location = System::Drawing::Point(392, 0);
			this->closeAddAdmin->Margin = System::Windows::Forms::Padding(0);
			this->closeAddAdmin->Name = L"closeAddAdmin";
			this->closeAddAdmin->Size = System::Drawing::Size(68, 79);
			this->closeAddAdmin->TabIndex = 18;
			this->closeAddAdmin->UseVisualStyleBackColor = false;
			this->closeAddAdmin->Click += gcnew System::EventHandler(this, &AddAdmin::closeAddAdmin_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10.2F));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(30, 255);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 23);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Password";
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10.2F));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(30, 176);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(92, 23);
			this->label10->TabIndex = 30;
			this->label10->Text = L"User Name";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->Location = System::Drawing::Point(34, 308);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(360, 3);
			this->panel2->TabIndex = 28;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel3->Location = System::Drawing::Point(34, 230);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(360, 3);
			this->panel3->TabIndex = 27;
			// 
			// txtAddPass
			// 
			this->txtAddPass->BackColor = System::Drawing::SystemColors::Control;
			this->txtAddPass->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtAddPass->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAddPass->Location = System::Drawing::Point(34, 281);
			this->txtAddPass->Multiline = true;
			this->txtAddPass->Name = L"txtAddPass";
			this->txtAddPass->PasswordChar = '*';
			this->txtAddPass->Size = System::Drawing::Size(365, 40);
			this->txtAddPass->TabIndex = 26;
			// 
			// txtAddUser
			// 
			this->txtAddUser->BackColor = System::Drawing::SystemColors::Control;
			this->txtAddUser->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtAddUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAddUser->ForeColor = System::Drawing::Color::Black;
			this->txtAddUser->Location = System::Drawing::Point(34, 202);
			this->txtAddUser->Multiline = true;
			this->txtAddUser->Name = L"txtAddUser";
			this->txtAddUser->Size = System::Drawing::Size(365, 40);
			this->txtAddUser->TabIndex = 25;
			// 
			// btnAddAdmin
			// 
			this->btnAddAdmin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddAdmin->BackColor = System::Drawing::Color::White;
			this->btnAddAdmin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAddAdmin->FlatAppearance->BorderSize = 0;
			this->btnAddAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btnAddAdmin->ForeColor = System::Drawing::Color::Black;
			this->btnAddAdmin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddAdmin.Image")));
			this->btnAddAdmin->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddAdmin->Location = System::Drawing::Point(116, 385);
			this->btnAddAdmin->Name = L"btnAddAdmin";
			this->btnAddAdmin->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btnAddAdmin->Size = System::Drawing::Size(222, 69);
			this->btnAddAdmin->TabIndex = 91;
			this->btnAddAdmin->Text = L"Add";
			this->btnAddAdmin->UseVisualStyleBackColor = false;
			this->btnAddAdmin->Click += gcnew System::EventHandler(this, &AddAdmin::btnAddAdmin_Click);
			// 
			// AddAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(460, 466);
			this->Controls->Add(this->btnAddAdmin);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->txtAddPass);
			this->Controls->Add(this->txtAddUser);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AddAdmin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddAdmin";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void closeAddAdmin_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnAddAdmin_Click(System::Object^ sender, System::EventArgs^ e) {


	SqlConnection^ con = Database::GetCon(); 
	String^ query =" INSERT INTO users(userName, password) VALUES(@UserName, @Password)";

	con->Open();
	SqlCommand^ cmd = gcnew SqlCommand(query, con);
	cmd->Parameters->AddWithValue("@UserName", txtAddUser->Text->Trim());
	cmd->Parameters->AddWithValue("@password", txtAddPass->Text->Trim());
	cmd->ExecuteNonQuery();
	con->Close();
	MessageBox::Show("Admin Added Successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			  
	txtAddUser->Text = ""; 
	txtAddPass->Text = "";
	this->Close(); 
	dataGridView->Rows->Clear();
	ClientController::LoadAdmin(dataGridView); 
	


}
};
}
