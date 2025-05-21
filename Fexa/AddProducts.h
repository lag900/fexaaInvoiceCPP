
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
    using namespace System::Data::SqlClient;
    using namespace System::IO;

    public ref class AddProducts : public System::Windows::Forms::Form
    {
    private:
        DataGridView^ dataGridView;
        Image^ editImg;
        Image^ delImg;
        bool isEditMode = false;
        String^ productId;
        String^ photoPath;
        FlowLayoutPanel^ flowLayoutPanel2;

    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Button^ closeAddProducts;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ ProductName;
    private: System::Windows::Forms::Panel^ panel5;
    private: System::Windows::Forms::ComboBox^ comboCategory;
    private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::Panel^ panel7;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Panel^ panel6;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::TextBox^ txtQuantity;
    private: System::Windows::Forms::TextBox^ txtDiscountedPrice;
    private: System::Windows::Forms::TextBox^ txtBuyingPrice;
    private: System::Windows::Forms::TextBox^ txtSellingPrice;
    private: System::Windows::Forms::TextBox^ txtProductName;
    private: System::Windows::Forms::Button^ btnUploadPhotoS;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::PictureBox^ pictureBoxPhoto;
    private: System::Windows::Forms::Button^ btnAddProduct;

    public:
        AddProducts(DataGridView^ dgv,Image^ edit, Image^ del, FlowLayoutPanel^ ds)
        {
            flowLayoutPanel2 = ds;
            dataGridView = dgv;
            editImg = edit;
            delImg = del;
            InitializeComponent();
            LoadCategories();
            comboCategory->SelectedIndex = -1;
            pictureBoxPhoto->SizeMode = PictureBoxSizeMode::StretchImage;
        }

        void SetProductData(String^ id, String^ name, String^ photo, String^ buyingPrice, String^ quantity,
            String^ sellingPrice, String^ discountedPrice, String^ category) {
            productId = id;
            txtProductName->Text = name;
            photoPath = photo; // تحديث photoPath بالمسار
            if (!String::IsNullOrEmpty(photoPath) && File::Exists(photoPath)) {
                try {
                    Image^ originalImage = Image::FromFile(photoPath);
                    int newWidth, newHeight;
                    if (originalImage->Width > originalImage->Height) {
                        newWidth = 50;
                        newHeight = (int)((double)originalImage->Height * 50 / originalImage->Width);
                    }
                    else {
                        newHeight = 50;
                        newWidth = (int)((double)originalImage->Width * 50 / originalImage->Height);
                    }
                    Bitmap^ resizedImage = gcnew Bitmap(originalImage, newWidth, newHeight);
                    pictureBoxPhoto->Image = resizedImage;
                    delete originalImage; // تحرير الملف الأصلي
                }
                catch (Exception^ ex) {
                   MessageBox::Show("Error occurred: " + ex->Message);
                   pictureBoxPhoto->Image = nullptr;
                }
            }
            else {
                if (!String::IsNullOrEmpty(photoPath)) {
                }
                pictureBoxPhoto->Image = nullptr; // إذا المسار غير موجود أو فارغ
            }
            txtBuyingPrice->Text = buyingPrice;
            txtQuantity->Text = quantity;
            txtSellingPrice->Text = sellingPrice;
            txtDiscountedPrice->Text = discountedPrice;
            comboCategory->Text = category;
            isEditMode = true;
            btnAddProduct->Text = L"Update";
        }

    protected:
        ~AddProducts()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

    private:
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddProducts::typeid));
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->closeAddProducts = (gcnew System::Windows::Forms::Button());
            this->btnAddProduct = (gcnew System::Windows::Forms::Button());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->ProductName = (gcnew System::Windows::Forms::Label());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->comboCategory = (gcnew System::Windows::Forms::ComboBox());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
            this->txtDiscountedPrice = (gcnew System::Windows::Forms::TextBox());
            this->txtBuyingPrice = (gcnew System::Windows::Forms::TextBox());
            this->txtSellingPrice = (gcnew System::Windows::Forms::TextBox());
            this->txtProductName = (gcnew System::Windows::Forms::TextBox());
            this->btnUploadPhotoS = (gcnew System::Windows::Forms::Button());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->pictureBoxPhoto = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panel1->SuspendLayout();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPhoto))->BeginInit();
            this->SuspendLayout();
            // 
            // label6
            // 
            this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16.2F, System::Drawing::FontStyle::Bold));
            this->label6->Location = System::Drawing::Point(96, 35);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(128, 38);
            this->label6->TabIndex = 17;
            this->label6->Text = L"Products";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(14, 20);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(76, 68);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Controls->Add(this->label6);
            this->panel1->Controls->Add(this->pictureBox1);
            this->panel1->Controls->Add(this->closeAddProducts);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(766, 109);
            this->panel1->TabIndex = 17;
            // 
            // closeAddProducts
            // 
            this->closeAddProducts->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->closeAddProducts->BackColor = System::Drawing::Color::White;
            this->closeAddProducts->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeAddProducts.BackgroundImage")));
            this->closeAddProducts->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->closeAddProducts->FlatAppearance->BorderSize = 0;
            this->closeAddProducts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->closeAddProducts->ForeColor = System::Drawing::Color::Transparent;
            this->closeAddProducts->Location = System::Drawing::Point(698, -6);
            this->closeAddProducts->Margin = System::Windows::Forms::Padding(0);
            this->closeAddProducts->Name = L"closeAddProducts";
            this->closeAddProducts->Size = System::Drawing::Size(68, 79);
            this->closeAddProducts->TabIndex = 1;
            this->closeAddProducts->UseVisualStyleBackColor = false;
            this->closeAddProducts->Click += gcnew System::EventHandler(this, &AddProducts::closeAddProducts_Click);
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
            this->btnAddProduct->Location = System::Drawing::Point(272, 632);
            this->btnAddProduct->Name = L"btnAddProduct";
            this->btnAddProduct->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
            this->btnAddProduct->Size = System::Drawing::Size(222, 69);
            this->btnAddProduct->TabIndex = 40;
            this->btnAddProduct->Text = L"Add";
            this->btnAddProduct->UseVisualStyleBackColor = false;
            this->btnAddProduct->Click += gcnew System::EventHandler(this, &AddProducts::btnAddProduct_Click);
            // 
            // label4
            // 
            this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->label4->Location = System::Drawing::Point(30, 280);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(69, 20);
            this->label4->TabIndex = 72;
            this->label4->Text = L"Category";
            // 
            // label5
            // 
            this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->label5->Location = System::Drawing::Point(233, 198);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(120, 20);
            this->label5->TabIndex = 73;
            this->label5->Text = L"Discounted Price";
            // 
            // label2
            // 
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->label2->Location = System::Drawing::Point(29, 204);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(90, 20);
            this->label2->TabIndex = 74;
            this->label2->Text = L"Buying Price";
            // 
            // label3
            // 
            this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->label3->Location = System::Drawing::Point(405, 283);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(35, 20);
            this->label3->TabIndex = 75;
            this->label3->Text = L"QTY";
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->label1->Location = System::Drawing::Point(468, 205);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(90, 20);
            this->label1->TabIndex = 76;
            this->label1->Text = L"Selling Price";
            // 
            // ProductName
            // 
            this->ProductName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->ProductName->AutoSize = true;
            this->ProductName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->ProductName->Location = System::Drawing::Point(32, 124);
            this->ProductName->Name = L"ProductName";
            this->ProductName->Size = System::Drawing::Size(60, 20);
            this->ProductName->TabIndex = 77;
            this->ProductName->Text = L"Product";
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->comboCategory);
            this->panel5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.2F));
            this->panel5->Location = System::Drawing::Point(34, 310);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(295, 40);
            this->panel5->TabIndex = 71;
            // 
            // comboCategory
            // 
            this->comboCategory->Location = System::Drawing::Point(-3, 0);
            this->comboCategory->Name = L"comboCategory";
            this->comboCategory->Size = System::Drawing::Size(298, 33);
            this->comboCategory->TabIndex = 18;
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::White;
            this->panel4->Location = System::Drawing::Point(409, 340);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(86, 3);
            this->panel4->TabIndex = 66;
            // 
            // panel7
            // 
            this->panel7->BackColor = System::Drawing::Color::White;
            this->panel7->Location = System::Drawing::Point(239, 258);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(126, 3);
            this->panel7->TabIndex = 68;
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::White;
            this->panel3->Location = System::Drawing::Point(33, 258);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(132, 3);
            this->panel3->TabIndex = 67;
            // 
            // panel6
            // 
            this->panel6->BackColor = System::Drawing::Color::White;
            this->panel6->Location = System::Drawing::Point(471, 258);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(129, 3);
            this->panel6->TabIndex = 69;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::White;
            this->panel2->Location = System::Drawing::Point(33, 185);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(631, 3);
            this->panel2->TabIndex = 70;
            // 
            // txtQuantity
            // 
            this->txtQuantity->BackColor = System::Drawing::SystemColors::Control;
            this->txtQuantity->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtQuantity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtQuantity->ForeColor = System::Drawing::Color::Black;
            this->txtQuantity->Location = System::Drawing::Point(406, 310);
            this->txtQuantity->Multiline = true;
            this->txtQuantity->Name = L"txtQuantity";
            this->txtQuantity->Size = System::Drawing::Size(103, 40);
            this->txtQuantity->TabIndex = 65;
            // 
            // txtDiscountedPrice
            // 
            this->txtDiscountedPrice->BackColor = System::Drawing::SystemColors::Control;
            this->txtDiscountedPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtDiscountedPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtDiscountedPrice->ForeColor = System::Drawing::Color::Black;
            this->txtDiscountedPrice->Location = System::Drawing::Point(236, 230);
            this->txtDiscountedPrice->Multiline = true;
            this->txtDiscountedPrice->Name = L"txtDiscountedPrice";
            this->txtDiscountedPrice->Size = System::Drawing::Size(143, 38);
            this->txtDiscountedPrice->TabIndex = 64;
            // 
            // txtBuyingPrice
            // 
            this->txtBuyingPrice->BackColor = System::Drawing::SystemColors::Control;
            this->txtBuyingPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtBuyingPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtBuyingPrice->ForeColor = System::Drawing::Color::Black;
            this->txtBuyingPrice->Location = System::Drawing::Point(30, 228);
            this->txtBuyingPrice->Multiline = true;
            this->txtBuyingPrice->Name = L"txtBuyingPrice";
            this->txtBuyingPrice->Size = System::Drawing::Size(149, 40);
            this->txtBuyingPrice->TabIndex = 63;
            // 
            // txtSellingPrice
            // 
            this->txtSellingPrice->BackColor = System::Drawing::SystemColors::Control;
            this->txtSellingPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtSellingPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtSellingPrice->ForeColor = System::Drawing::Color::Black;
            this->txtSellingPrice->Location = System::Drawing::Point(468, 228);
            this->txtSellingPrice->Multiline = true;
            this->txtSellingPrice->Name = L"txtSellingPrice";
            this->txtSellingPrice->Size = System::Drawing::Size(146, 40);
            this->txtSellingPrice->TabIndex = 62;
            // 
            // txtProductName
            // 
            this->txtProductName->BackColor = System::Drawing::SystemColors::Control;
            this->txtProductName->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtProductName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtProductName->ForeColor = System::Drawing::Color::Black;
            this->txtProductName->Location = System::Drawing::Point(30, 155);
            this->txtProductName->Multiline = true;
            this->txtProductName->Name = L"txtProductName";
            this->txtProductName->Size = System::Drawing::Size(648, 40);
            this->txtProductName->TabIndex = 61;
            // 
            // btnUploadPhotoS
            // 
            this->btnUploadPhotoS->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnUploadPhotoS->BackColor = System::Drawing::Color::Red;
            this->btnUploadPhotoS->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->btnUploadPhotoS->FlatAppearance->BorderSize = 0;
            this->btnUploadPhotoS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnUploadPhotoS->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8, System::Drawing::FontStyle::Bold));
            this->btnUploadPhotoS->ForeColor = System::Drawing::Color::White;
            this->btnUploadPhotoS->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUploadPhotoS.Image")));
            this->btnUploadPhotoS->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
            this->btnUploadPhotoS->Location = System::Drawing::Point(61, 603);
            this->btnUploadPhotoS->Name = L"btnUploadPhotoS";
            this->btnUploadPhotoS->Size = System::Drawing::Size(133, 44);
            this->btnUploadPhotoS->TabIndex = 60;
            this->btnUploadPhotoS->Text = L"Upload";
            this->btnUploadPhotoS->UseVisualStyleBackColor = false;
            this->btnUploadPhotoS->Click += gcnew System::EventHandler(this, &AddProducts::btnUploadPhoto_Click);
            // 
            // label7
            // 
            this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->label7->Location = System::Drawing::Point(34, 363);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(48, 20);
            this->label7->TabIndex = 59;
            this->label7->Text = L"Photo";
            // 
            // pictureBoxPhoto
            // 
            this->pictureBoxPhoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxPhoto.Image")));
            this->pictureBoxPhoto->Location = System::Drawing::Point(33, 397);
            this->pictureBoxPhoto->Name = L"pictureBoxPhoto";
            this->pictureBoxPhoto->Size = System::Drawing::Size(199, 200);
            this->pictureBoxPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBoxPhoto->TabIndex = 58;
            this->pictureBoxPhoto->TabStop = false;
            // 
            // AddProducts
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(766, 723);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->ProductName);
            this->Controls->Add(this->panel5);
            this->Controls->Add(this->panel4);
            this->Controls->Add(this->panel7);
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->panel6);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->txtQuantity);
            this->Controls->Add(this->txtDiscountedPrice);
            this->Controls->Add(this->txtBuyingPrice);
            this->Controls->Add(this->txtSellingPrice);
            this->Controls->Add(this->txtProductName);
            this->Controls->Add(this->btnUploadPhotoS);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->pictureBoxPhoto);
            this->Controls->Add(this->btnAddProduct);
            this->Controls->Add(this->panel1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"AddProducts";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Add";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel5->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPhoto))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        void LoadCategories() {
            SqlConnection^ conn = Database::GetCon();
            try {
                conn->Open();
                String^ query = "SELECT category_name FROM Categories";
                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                SqlDataReader^ reader = cmd->ExecuteReader();
                comboCategory->Items->Clear();
                while (reader->Read()) {
                    comboCategory->Items->Add(reader["category_name"]->ToString());
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error downloading categories: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally {
                if (conn->State == ConnectionState::Open) {
                    conn->Close();
                }
            }
        }

        void btnUploadPhoto_Click(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp";
            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                photoPath = openFileDialog->FileName;
                pictureBoxPhoto->Image = Image::FromFile(photoPath);
            }
        }

        void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ name = txtProductName->Text;
            String^ buyingPrice = txtBuyingPrice->Text;
            String^ quantity = txtQuantity->Text;
            String^ sellingPrice = txtSellingPrice->Text;
            String^ discountedPrice = txtDiscountedPrice->Text;
            String^ category = comboCategory->Text;

            // Check for empty fields
            if (String::IsNullOrEmpty(name) || String::IsNullOrEmpty(buyingPrice) ||
                String::IsNullOrEmpty(quantity) || String::IsNullOrEmpty(sellingPrice) ||
                String::IsNullOrEmpty(discountedPrice) || String::IsNullOrEmpty(category)) {
                MessageBox::Show("Please fill in all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Validate numeric values
            try {
                Convert::ToDecimal(buyingPrice);
                Convert::ToInt32(quantity);
                Convert::ToDecimal(sellingPrice);
                Convert::ToDecimal(discountedPrice);
            }
            catch (Exception^) {
                MessageBox::Show("Please enter valid numeric values.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            SqlConnection^ con = Database::GetCon();
            String^ query;
            SqlCommand^ cmd = nullptr;
            int rowsAffected = 0;

            try {
                con->Open();
                if (isEditMode) {
                    // When editing, keep the original photo if unchanged
                    query = "UPDATE Product SET ProductName = @name, Photo = @photo, BuyingPrice = @buyingPrice, Quantity = @quantity, "
                        "SellingPrice = @sellingPrice, DiscountedPrice = @discountedPrice, CategoryName = @categoryName "
                        "WHERE ProductID = @id";
                    cmd = gcnew SqlCommand(query, con);
                    cmd->Parameters->AddWithValue("@name", name);
                    // إذا كان المستخدم لم يغير الصورة (photoPath فارغ)، استخدم القيمة الأصلية
                    // إذا كان photoPath فارغ ولا توجد قيمة أصلية، أرسل DBNull
                    cmd->Parameters->AddWithValue("@photo", String::IsNullOrEmpty(photoPath) ? DBNull::Value : (Object^)photoPath);
                    cmd->Parameters->AddWithValue("@buyingPrice", Convert::ToDecimal(buyingPrice));
                    cmd->Parameters->AddWithValue("@quantity", Convert::ToInt32(quantity));
                    cmd->Parameters->AddWithValue("@sellingPrice", Convert::ToDecimal(sellingPrice));
                    cmd->Parameters->AddWithValue("@discountedPrice", Convert::ToDecimal(discountedPrice));
                    cmd->Parameters->AddWithValue("@categoryName", category);
                    cmd->Parameters->AddWithValue("@id", Convert::ToInt32(productId));
                }
                else {
                    query = "INSERT INTO Product (ProductName, Photo, BuyingPrice, Quantity, SellingPrice, DiscountedPrice, CategoryName) "
                        "VALUES (@name, @photo, @buyingPrice, @quantity, @sellingPrice, @discountedPrice, @categoryName)";
                    cmd = gcnew SqlCommand(query, con);
                    cmd->Parameters->AddWithValue("@name", name);
                    cmd->Parameters->AddWithValue("@photo", String::IsNullOrEmpty(photoPath) ? DBNull::Value : (Object^)photoPath);
                    cmd->Parameters->AddWithValue("@buyingPrice", Convert::ToDecimal(buyingPrice));
                    cmd->Parameters->AddWithValue("@quantity", Convert::ToInt32(quantity));
                    cmd->Parameters->AddWithValue("@sellingPrice", Convert::ToDecimal(sellingPrice));
                    cmd->Parameters->AddWithValue("@discountedPrice", Convert::ToDecimal(discountedPrice));
                    cmd->Parameters->AddWithValue("@categoryName", category);
                }

                rowsAffected = cmd->ExecuteNonQuery();
                if (rowsAffected > 0) {
                    MessageBox::Show(isEditMode ? "Product updated successfully!" : "Product added successfully: " + name,
                        "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                    // Reset fields
                    txtProductName->Clear();
                    txtBuyingPrice->Clear();
                    txtQuantity->Clear();
                    txtSellingPrice->Clear();
                    txtDiscountedPrice->Clear();
                    comboCategory->SelectedIndex = -1;
                    pictureBoxPhoto->Image = nullptr;
                    photoPath = nullptr;

                    dataGridView->Rows->Clear();
                    ClientController::LoadProducts(dataGridView, editImg, delImg, String::Empty);
                    ClientController::LoadProductCards(flowLayoutPanel2, "");


                    this->Close();
                }
                else {
                    MessageBox::Show(isEditMode ? "Failed to update product." : "Failed to add product.",
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
  private: System::Void closeAddProducts_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    private: System::Void comboCategory_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}