#pragma once
#include "MyForm.h"

namespace Fexa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
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
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pn_title;
	protected:
	private: System::Windows::Forms::Button^ min;
	private: System::Windows::Forms::Button^ max;
	private: System::Windows::Forms::Button^ close;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->pn_title = (gcnew System::Windows::Forms::Panel());
			this->min = (gcnew System::Windows::Forms::Button());
			this->max = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->pn_title->SuspendLayout();
			this->SuspendLayout();
			// 
			// pn_title
			// 
			this->pn_title->BackColor = System::Drawing::Color::White;
			this->pn_title->Controls->Add(this->min);
			this->pn_title->Controls->Add(this->max);
			this->pn_title->Controls->Add(this->close);
			this->pn_title->Dock = System::Windows::Forms::DockStyle::Top;
			this->pn_title->Location = System::Drawing::Point(0, 0);
			this->pn_title->Name = L"pn_title";
			this->pn_title->Size = System::Drawing::Size(958, 49);
			this->pn_title->TabIndex = 2;
			// 
			// min
			// 
			this->min->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"min.BackgroundImage")));
			this->min->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->min->FlatAppearance->BorderSize = 0;
			this->min->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->min->ForeColor = System::Drawing::Color::Transparent;
			this->min->Location = System::Drawing::Point(781, -6);
			this->min->Margin = System::Windows::Forms::Padding(0);
			this->min->Name = L"min";
			this->min->Size = System::Drawing::Size(57, 57);
			this->min->TabIndex = 0;
			this->min->UseVisualStyleBackColor = true;
			// 
			// max
			// 
			this->max->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->max->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max.BackgroundImage")));
			this->max->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->max->FlatAppearance->BorderSize = 0;
			this->max->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->max->ForeColor = System::Drawing::Color::Transparent;
			this->max->Location = System::Drawing::Point(838, -6);
			this->max->Margin = System::Windows::Forms::Padding(0);
			this->max->Name = L"max";
			this->max->Size = System::Drawing::Size(57, 57);
			this->max->TabIndex = 0;
			this->max->UseVisualStyleBackColor = true;
			// 
			// close
			// 
			this->close->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.BackgroundImage")));
			this->close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->close->FlatAppearance->BorderSize = 0;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->ForeColor = System::Drawing::Color::Transparent;
			this->close->Location = System::Drawing::Point(901, -6);
			this->close->Margin = System::Windows::Forms::Padding(0);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(57, 57);
			this->close->TabIndex = 0;
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &MyForm2::close_Click);
			// 
			// MyForm2
			// 
			this->AccessibleDescription = L"log";
			this->AccessibleName = L"log";
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(958, 578);
			this->Controls->Add(this->pn_title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"log";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->pn_title->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
	     this->Close();
	}
};
}
