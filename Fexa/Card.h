#pragma once

namespace Fexa {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for ProductCard (معدل من card)
    /// </summary>
    public ref class ProductCard : public System::Windows::Forms::UserControl {
    private:
        System::Windows::Forms::PictureBox^ photoProduct;
        System::Windows::Forms::Label^ nameCard;
        System::Windows::Forms::Label^ price;
        System::Windows::Forms::TextBox^ txtQTY;
        System::Windows::Forms::Button^ plus;
        System::Windows::Forms::Button^ mins;
        System::Windows::Forms::Button^ addInv;

        String^ productId;
        String^ productName;
        String^ productPrice;
        int qty;
        String^ pathPhoto;

    public:
        // حدث لإضافة المنتج للفاتورة
        delegate void AddToInvoiceHandler(String^ productId, String^ productName, String^ productPrice, int quantity);
        event AddToInvoiceHandler^ OnAddToInvoice;

        ProductCard(void) {
            InitializeComponent();
            qty = 0;
            txtQTY->Text = qty.ToString();
        }

        void SetCardData(String^ id, String^ name, String^ price, String^ pathPhoto) {
            productId = id;
            productName = name;
            productPrice = price;
            this->pathPhoto = pathPhoto;
            nameCard->Text = productName;
            this->price->Text = productPrice;

            if (!String::IsNullOrEmpty(pathPhoto) && System::IO::File::Exists(pathPhoto)) {
                try {
                    photoProduct->Image = Image::FromFile(pathPhoto);
                    photoProduct->SizeMode = PictureBoxSizeMode::StretchImage;
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error loading image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        String^ GetProductName() {
            return productName;
        }

    protected:
        ~ProductCard() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProductCard::typeid));
            this->photoProduct = (gcnew System::Windows::Forms::PictureBox());
            this->txtQTY = (gcnew System::Windows::Forms::TextBox());
            this->plus = (gcnew System::Windows::Forms::Button());
            this->mins = (gcnew System::Windows::Forms::Button());
            this->nameCard = (gcnew System::Windows::Forms::Label());
            this->addInv = (gcnew System::Windows::Forms::Button());
            this->price = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoProduct))->BeginInit();
            this->SuspendLayout();
            // 
            // photoProduct
            // 
            this->photoProduct->Location = System::Drawing::Point(29, 16);
            this->photoProduct->Name = L"photoProduct";
            this->photoProduct->Size = System::Drawing::Size(184, 127);
            this->photoProduct->TabIndex = 0;
            this->photoProduct->TabStop = false;
            // 
            // txtQTY
            // 
            this->txtQTY->BackColor = System::Drawing::SystemColors::Control;
            this->txtQTY->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtQTY->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtQTY->ForeColor = System::Drawing::Color::Black;
            this->txtQTY->Location = System::Drawing::Point(103, 170);
            this->txtQTY->Multiline = true;
            this->txtQTY->Name = L"txtQTY";
            this->txtQTY->ReadOnly = true;
            this->txtQTY->Size = System::Drawing::Size(50, 30);
            this->txtQTY->TabIndex = 67;
            this->txtQTY->Text = L"0";
            // 
            // plus
            // 
            this->plus->BackColor = System::Drawing::Color::White;
            this->plus->FlatAppearance->BorderSize = 0;
            this->plus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->plus->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 12, System::Drawing::FontStyle::Bold));
            this->plus->ForeColor = System::Drawing::Color::Red;
            this->plus->Location = System::Drawing::Point(151, 169);
            this->plus->Name = L"plus";
            this->plus->Size = System::Drawing::Size(30, 30);
            this->plus->TabIndex = 69;
            this->plus->Text = L"+";
            this->plus->UseVisualStyleBackColor = false;
            this->plus->Click += gcnew System::EventHandler(this, &ProductCard::plus_Click);
            // 
            // mins
            // 
            this->mins->BackColor = System::Drawing::Color::White;
            this->mins->FlatAppearance->BorderSize = 0;
            this->mins->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->mins->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 12, System::Drawing::FontStyle::Bold));
            this->mins->ForeColor = System::Drawing::Color::Red;
            this->mins->Location = System::Drawing::Point(67, 169);
            this->mins->Name = L"mins";
            this->mins->Size = System::Drawing::Size(30, 30);
            this->mins->TabIndex = 69;
            this->mins->Text = L"-";
            this->mins->UseVisualStyleBackColor = false;
            this->mins->Click += gcnew System::EventHandler(this, &ProductCard::mins_Click);
            // 
            // nameCard
            // 
            this->nameCard->AutoSize = true;
            this->nameCard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->nameCard->Location = System::Drawing::Point(69, 146);
            this->nameCard->Name = L"nameCard";
            this->nameCard->Size = System::Drawing::Size(104, 20);
            this->nameCard->TabIndex = 78;
            this->nameCard->Text = L"Product Name";
            this->nameCard->Click += gcnew System::EventHandler(this, &ProductCard::nameCard_Click);
            // 
            // addInv
            // 
            this->addInv->BackColor = System::Drawing::Color::White;
            this->addInv->FlatAppearance->BorderSize = 0;
            this->addInv->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->addInv->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
            this->addInv->ForeColor = System::Drawing::Color::Black;
            this->addInv->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addInv.Image")));
            this->addInv->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->addInv->Location = System::Drawing::Point(44, 256);
            this->addInv->Name = L"addInv";
            this->addInv->Size = System::Drawing::Size(154, 30);
            this->addInv->TabIndex = 79;
            this->addInv->Text = L"Add to Invoice";
            this->addInv->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->addInv->UseVisualStyleBackColor = false;
            this->addInv->Click += gcnew System::EventHandler(this, &ProductCard::addInv_Click);
            // 
            // price
            // 
            this->price->AutoSize = true;
            this->price->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->price->ForeColor = System::Drawing::Color::Red;
            this->price->Location = System::Drawing::Point(62, 214);
            this->price->Name = L"price";
            this->price->Size = System::Drawing::Size(120, 28);
            this->price->TabIndex = 78;
            this->price->Text = L"100.00 EGP";
            // 
            // ProductCard
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->Controls->Add(this->addInv);
            this->Controls->Add(this->price);
            this->Controls->Add(this->nameCard);
            this->Controls->Add(this->mins);
            this->Controls->Add(this->plus);
            this->Controls->Add(this->txtQTY);
            this->Controls->Add(this->photoProduct);
            this->Name = L"ProductCard";
            this->Size = System::Drawing::Size(243, 303);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoProduct))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void plus_Click(System::Object^ sender, System::EventArgs^ e) {
            qty++;
            txtQTY->Text = qty.ToString();
        }

        System::Void mins_Click(System::Object^ sender, System::EventArgs^ e) {
            if (qty > 0) {
                qty--;
                txtQTY->Text = qty.ToString();
            }
            else {
                txtQTY->Text = "0";
            }
        }

        System::Void addInv_Click(System::Object^ sender, System::EventArgs^ e) {
            if (qty > 0) {
                OnAddToInvoice(productId, productName, productPrice, qty);
            }
            else {
                MessageBox::Show("Please select a quantity greater than 0.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }
    private: System::Void nameCard_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}