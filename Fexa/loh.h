#pragma once
#include "MyForm.h"
using namespace System::Data::SqlClient;

namespace Fexa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for loh
	/// </summary>
	public ref class loh : public System::Windows::Forms::Form
	{
	public:
		loh(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~loh()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
















	private: System::Windows::Forms::Button^ btn_home;





	private: System::Windows::Forms::TextBox^ txtUser;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtPass;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label1;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(loh::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_home = (gcnew System::Windows::Forms::Button());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(41, 199);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(274, 182);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(474, 55);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(175, 125);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// btn_home
			// 
			this->btn_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_home->BackColor = System::Drawing::Color::Red;
			this->btn_home->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_home->FlatAppearance->BorderSize = 0;
			this->btn_home->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_home->ForeColor = System::Drawing::Color::White;
			this->btn_home->Location = System::Drawing::Point(415, 436);
			this->btn_home->Name = L"btn_home";
			this->btn_home->Size = System::Drawing::Size(145, 55);
			this->btn_home->TabIndex = 2;
			this->btn_home->Text = L"Login";
			this->btn_home->UseVisualStyleBackColor = false;
			this->btn_home->Click += gcnew System::EventHandler(this, &loh::btn_home_Click);
			// 
			// txtUser
			// 
			this->txtUser->BackColor = System::Drawing::SystemColors::Control;
			this->txtUser->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUser->ForeColor = System::Drawing::Color::Black;
			this->txtUser->Location = System::Drawing::Point(423, 298);
			this->txtUser->Multiline = true;
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(293, 40);
			this->txtUser->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(423, 326);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(288, 3);
			this->panel1->TabIndex = 9;
			// 
			// txtPass
			// 
			this->txtPass->BackColor = System::Drawing::SystemColors::Control;
			this->txtPass->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtPass->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPass->Location = System::Drawing::Point(423, 377);
			this->txtPass->Multiline = true;
			this->txtPass->Name = L"txtPass";
			this->txtPass->PasswordChar = '*';
			this->txtPass->Size = System::Drawing::Size(293, 40);
			this->txtPass->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->Location = System::Drawing::Point(423, 404);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(288, 3);
			this->panel2->TabIndex = 10;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::LightGray;
			this->panel3->Location = System::Drawing::Point(352, 114);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(3, 337);
			this->panel3->TabIndex = 11;
			// 
			// exit
			// 
			this->exit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exit->BackColor = System::Drawing::SystemColors::Control;
			this->exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit->ForeColor = System::Drawing::Color::Red;
			this->exit->Location = System::Drawing::Point(566, 436);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(150, 55);
			this->exit->TabIndex = 2;
			this->exit->Text = L"Exit";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &loh::exit_Click);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 22.2F));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(432, 183);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(254, 50);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Welcome Back";
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10.2F));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(419, 261);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 23);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Name";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10.2F));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(419, 341);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 23);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Password";
			this->label1->Click += gcnew System::EventHandler(this, &loh::label1_Click);
			// 
			// loh
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 531);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->btn_home);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"loh";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"loh";
			this->Load += gcnew System::EventHandler(this, &loh::loh_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loh_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void box_cat_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void btn_home_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ User = this->txtUser->Text;
	String^ pass = this->txtPass->Text;
	String^ connectionString = "Data Source=DESKTOP-6E83744;Initial Catalog=store;Integrated Security=True";
	SqlConnection^ conn = gcnew SqlConnection(connectionString);
	if(User->Length==0 || pass->Length==0)
	{
		MessageBox::Show("Please Enter Your Email And Passwprd");

		return;
	}
	try {
		conn->Open();
		String^ query = "SELECT COUNT(*) FROM users WHERE username = @username AND password = @password";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@username", User);
		cmd->Parameters->AddWithValue("@password", pass);

		int count = (int)cmd->ExecuteScalar();

		if (count > 0) {
			// لو اليوزر موجود
			// هنا ممكن تفتح Form جديد أو تكمل البرنامج
			MyForm^ base = gcnew MyForm;

			base->Show();

		}
		else {
			// لو اليوزر مش موجود
			MessageBox::Show("Invalid username or password!", "Error");
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Database Error");

	}
	finally {
		conn->Close();
	}

	

}
private: System::Void separatorControl1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();


}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
