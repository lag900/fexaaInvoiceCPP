#pragma once

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
	public ref class AddExop : public System::Windows::Forms::Form
	{
	public:
		AddExop(void)
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
		~AddExop()
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
	private: System::Windows::Forms::TextBox^ txtBuyingPrice;
	private: System::Windows::Forms::TextBox^ txtSellingPrice;
	private: System::Windows::Forms::TextBox^ txtProductName;
	private: System::Windows::Forms::Button^ btnAddProduct;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddExop::typeid));
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
			this->txtBuyingPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtSellingPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtProductName = (gcnew System::Windows::Forms::TextBox());
			this->btnAddProduct = (gcnew System::Windows::Forms::Button());
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
			this->closeAddExpo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeAddExpo.BackgroundImage")));
			this->closeAddExpo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->closeAddExpo->FlatAppearance->BorderSize = 0;
			this->closeAddExpo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeAddExpo->ForeColor = System::Drawing::Color::Transparent;
			this->closeAddExpo->Location = System::Drawing::Point(555, 0);
			this->closeAddExpo->Margin = System::Windows::Forms::Padding(0);
			this->closeAddExpo->Name = L"closeAddExpo";
			this->closeAddExpo->Size = System::Drawing::Size(68, 79);
			this->closeAddExpo->TabIndex = 2;
			this->closeAddExpo->UseVisualStyleBackColor = false;
			this->closeAddExpo->Click += gcnew System::EventHandler(this, &AddExop::closeAddExpo_Click);
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
			this->label1->Size = System::Drawing::Size(46, 20);
			this->label1->TabIndex = 88;
			this->label1->Text = L"Note ";
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
			// txtBuyingPrice
			// 
			this->txtBuyingPrice->BackColor = System::Drawing::SystemColors::Control;
			this->txtBuyingPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBuyingPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBuyingPrice->ForeColor = System::Drawing::Color::Black;
			this->txtBuyingPrice->Location = System::Drawing::Point(16, 262);
			this->txtBuyingPrice->Multiline = true;
			this->txtBuyingPrice->Name = L"txtBuyingPrice";
			this->txtBuyingPrice->Size = System::Drawing::Size(149, 40);
			this->txtBuyingPrice->TabIndex = 80;
			// 
			// txtSellingPrice
			// 
			this->txtSellingPrice->BackColor = System::Drawing::SystemColors::Control;
			this->txtSellingPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtSellingPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSellingPrice->ForeColor = System::Drawing::Color::Black;
			this->txtSellingPrice->Location = System::Drawing::Point(258, 262);
			this->txtSellingPrice->Multiline = true;
			this->txtSellingPrice->Name = L"txtSellingPrice";
			this->txtSellingPrice->Size = System::Drawing::Size(328, 40);
			this->txtSellingPrice->TabIndex = 79;
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
			// btnAddProduct
			// 
			this->btnAddProduct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddProduct->BackColor = System::Drawing::Color::White;
			this->btnAddProduct->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAddProduct->FlatAppearance->BorderSize = 0;
			this->btnAddProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
			this->btnAddProduct->ForeColor = System::Drawing::Color::Black;
			this->btnAddProduct->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddProduct.Image")));
			this->btnAddProduct->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddProduct->Location = System::Drawing::Point(194, 381);
			this->btnAddProduct->Name = L"btnAddProduct";
			this->btnAddProduct->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
			this->btnAddProduct->Size = System::Drawing::Size(222, 69);
			this->btnAddProduct->TabIndex = 90;
			this->btnAddProduct->Text = L"Add";
			this->btnAddProduct->UseVisualStyleBackColor = false;
			// 
			// AddExop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(623, 462);
			this->Controls->Add(this->btnAddProduct);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ProductName);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->txtBuyingPrice);
			this->Controls->Add(this->txtSellingPrice);
			this->Controls->Add(this->txtProductName);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AddExop";
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
	};
}
