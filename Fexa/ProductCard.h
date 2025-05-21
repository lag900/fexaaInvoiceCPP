//ProductCard
#pragma once   // هنا انا بقوله ان كلاس الي هنا مش يكون لي نسخة تاني منه في نفس البرنامج 
#include "ClientController.h"
namespace Fexa {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

	// هنا كلاس بتاعنا بيورث من كلاس تاني اسمه UserControl
	///  UserControl :  هو كلاس موجود في مكتبة System::Windows::Forms
	///  وده كلاس بيستخدم في بناء واجهات المستخدم (UI) في تطبيقات Windows Forms
	/// عشان لو عاوزين نعمل كارت جديد نقدر نستخدمه في أي مكان في البرنامج
	/// Resuable :  يعني لو عاوزين نستخدمه في مكان تاني في البرنامج
    public ref class ProductCard : public System::Windows::Forms::UserControl {
    private:
		int maxQty;  //   ده غرض منه الكمية المتاحة من  كل منتج
		String^ productId;     // ده غرض منه رقم المنتج
		String^ productName;      //  ده غرض منه اسم المنتج
		String^ productPrice;         //  ده غرض منه سعر المنتج (المشطوب 
		String^ discountedPrice;          //    ده غرض منه سعر المنتج بعد الخصم
		int qty;                          // ده غرض منه الكمية الي انا عاوزها من المنتج
		String^ pathPhoto; // ده غرض منه مسار الصورة بتاع المنتج


    private: System::Windows::Forms::PictureBox^ photoProduct;
    private: System::Windows::Forms::TextBox^ txtQTY;
    private: System::Windows::Forms::Button^ plus;
    private: System::Windows::Forms::Button^ mins;
    private: System::Windows::Forms::Label^ nameCard;
    private: System::Windows::Forms::Label^ price;
    private: System::Windows::Forms::Button^ addInv;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Label^ label1;



    public:
  

        ProductCard(void) {
            InitializeComponent();
            qty = 0;
            txtQTY->Text = qty.ToString();
        }

		//  Delegate : انا هنا بشاور علي داله دي وبقوله خلي بالك اني هعاوزها بعدين 
		//  Event :  انا هنا بقول للبرنامج اني هستخدم الداله دي في مكان تاني ولما يحصل حدث معين 
		//  هنا انا بقول للبرنامج اني هستخدم الداله دي في مكان تاني ولما يحصل حدث معين  لما اضغط علي زر الاضافة

        delegate void AddToInvoiceHandler(String^ productId, String^ productName, String^ sellingPrice, int quantity, String^ discountedPrice, String^ total);
        event AddToInvoiceHandler^ OnAddToInvoice;

		// دالة دي عشان اجيب البيانات من الكارت

        void SetCardData(String^ id, String^ name, String^ price, String^ dis, String^ pathPhoto, int availableQty ) {
            productId = id;
            productName = name;
            productPrice = price;
			discountedPrice = dis;
            this->pathPhoto = pathPhoto;
            maxQty = availableQty;
            nameCard->Text = productName;
			this->label1->Text = productPrice; 
            this->price->Text = discountedPrice;
          
			/// هنا انا بقول للبرنامج اني عاوز احط الصورة في الكارت
			///  وانا بقول له ان الصورة هتكون من المسار الي انا حطيته في الكارت
			/// عشان انا مش عاوز يعمل كراش للصورة في الميموري
            /// 
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
       virtual ~ProductCard() {
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
            this->price = (gcnew System::Windows::Forms::Label());
            this->addInv = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoProduct))->BeginInit();
            this->panel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // photoProduct
            // 
            this->photoProduct->Location = System::Drawing::Point(21, 22);
            this->photoProduct->Name = L"photoProduct";
            this->photoProduct->Size = System::Drawing::Size(153, 101);
            this->photoProduct->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
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
            this->txtQTY->Location = System::Drawing::Point(74, 165);
            this->txtQTY->Multiline = true;
            this->txtQTY->Name = L"txtQTY";
            this->txtQTY->ReadOnly = true;
            this->txtQTY->Size = System::Drawing::Size(56, 30);
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
            this->plus->Location = System::Drawing::Point(136, 164);
            this->plus->Name = L"plus";
            this->plus->Size = System::Drawing::Size(36, 30);
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
            this->mins->Location = System::Drawing::Point(35, 164);
            this->mins->Name = L"mins";
            this->mins->Size = System::Drawing::Size(36, 30);
            this->mins->TabIndex = 69;
            this->mins->Text = L"-";
            this->mins->UseVisualStyleBackColor = false;
            this->mins->Click += gcnew System::EventHandler(this, &ProductCard::mins_Click);
            // 
            // nameCard
            // 
            this->nameCard->AutoSize = true;
            this->nameCard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->nameCard->Location = System::Drawing::Point(38, 126);
            this->nameCard->Margin = System::Windows::Forms::Padding(0);
            this->nameCard->MaximumSize = System::Drawing::Size(140, 100);
            this->nameCard->Name = L"nameCard";
            this->nameCard->Size = System::Drawing::Size(92, 17);
            this->nameCard->TabIndex = 78;
            this->nameCard->Text = L"Product Name";
            // 
            // price
            // 
            this->price->AutoSize = true;
            this->price->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->price->ForeColor = System::Drawing::Color::Red;
            this->price->Location = System::Drawing::Point(36, 216);
            this->price->Name = L"price";
            this->price->Size = System::Drawing::Size(108, 28);
            this->price->TabIndex = 78;
            this->price->Text = L"90.00 EGP";
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
            this->addInv->Location = System::Drawing::Point(14, 247);
            this->addInv->Name = L"addInv";
            this->addInv->Size = System::Drawing::Size(160, 30);
            this->addInv->TabIndex = 79;
            this->addInv->Text = L"Add to Invoice";
            this->addInv->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->addInv->UseVisualStyleBackColor = false;
            this->addInv->Click += gcnew System::EventHandler(this, &ProductCard::addInv_Click);
            // 
            // panel1
            // 
            this->panel1->Controls->Add(this->addInv);
            this->panel1->Controls->Add(this->label1);
            this->panel1->Controls->Add(this->price);
            this->panel1->Controls->Add(this->nameCard);
            this->panel1->Controls->Add(this->mins);
            this->panel1->Controls->Add(this->plus);
            this->panel1->Controls->Add(this->txtQTY);
            this->panel1->Controls->Add(this->photoProduct);
            this->panel1->Location = System::Drawing::Point(-1, -1);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(188, 290);
            this->panel1->TabIndex = 81;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Strikeout, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::Gray;
            this->label1->Location = System::Drawing::Point(50, 198);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 20);
            this->label1->TabIndex = 78;
            this->label1->Text = L"100.00 EGP";
            // 
            // ProductCard
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->panel1);
            this->Margin = System::Windows::Forms::Padding(10);
            this->Name = L"ProductCard";
            this->Size = System::Drawing::Size(187, 289);
            this->Load += gcnew System::EventHandler(this, &ProductCard::ProductCard_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoProduct))->EndInit();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void plus_Click(System::Object^ sender, System::EventArgs^ e) {
            if (qty < maxQty) {
                qty++;
                txtQTY->Text = qty.ToString();
            }
            else {
                MessageBox::Show("Cannot exceed available quantity: " + maxQty.ToString(), "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

        System::Void mins_Click(System::Object^ sender, System::EventArgs^ e) {
            if (qty > 0) {
                qty--;
                txtQTY->Text = qty.ToString();
            }
        }

private: System::Void addInv_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (qty <= 0) {
            MessageBox::Show("Please select a quantity greater than zero.", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // تنظيف السعر قبل وبعد الخصم
        String^ cleanProductPrice = productPrice->Trim()->Replace(" EGP", "");
        String^ cleanDiscountedPrice = discountedPrice->Trim()->Replace(" EGP", "");

        Decimal sellingPrice;
        Decimal discountedPriceValue;

        // تحويل السعر بأمان
        if (!Decimal::TryParse(cleanProductPrice, Globalization::NumberStyles::Any,
            Globalization::CultureInfo::InvariantCulture, sellingPrice)) {
            MessageBox::Show("Invalid product price before discount: " + cleanProductPrice, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (!Decimal::TryParse(cleanDiscountedPrice, Globalization::NumberStyles::Any,
            Globalization::CultureInfo::InvariantCulture, discountedPriceValue)) {
            MessageBox::Show("Invalid product price after discount: " + cleanDiscountedPrice, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // حساب الإجمالي
        Decimal total = qty * discountedPriceValue;

        // استدعاء الحدث
        OnAddToInvoice(productId, productName, sellingPrice.ToString("F2") + " EGP", qty,
            discountedPriceValue.ToString("F2") + " EGP", total.ToString("F2") + " EGP");

        // إعادة تعيين الكمية
        qty = 0;
        txtQTY->Text = "0";
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error adding product to invoice: " + ex->Message, "Error",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
    private:
        System::Void nameCard_Click(System::Object^ sender, System::EventArgs^ e) {
        }
    private: System::Void ProductCard_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}