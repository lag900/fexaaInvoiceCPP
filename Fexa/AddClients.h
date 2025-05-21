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

    public ref class AddClients : public System::Windows::Forms::Form
    {
    private:
        DataGridView^ dataGridView;
        Image^ editImg;
        Image^ delImg;
        bool isEditMode = false; // تعديل النوع إلى bool
        String^ clientId; // متغير جديد لتخزين الـ ID

    private:
        System::Windows::Forms::DataGridView^ dataClient;

    public:
        AddClients(DataGridView^ dgv, Image^ edit, Image^ del)
        {
            dataGridView = dgv;
            editImg = edit;
            delImg = del;
            InitializeComponent();
            comboCity->SelectedIndex = -1;
        }

    public:
        void SetClientData(String^ id, String^ name, String^ phone, String^ email, String^ city, String^ location) {
            clientId = id;
            txtClientName->Text = name;
            txtClientPhone->Text = phone;
            txtClientEmail->Text = email;
            comboCity->Text = city;
            txtClientLocation->Text = location;
            isEditMode = true;
            this->btn_newClient->Text = L"Update";
        }

    protected:
        ~AddClients()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Form controls
        System::Windows::Forms::Panel^ panel1;
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Button^ closeAddClients;
        System::Windows::Forms::Panel^ panel2;
        System::Windows::Forms::TextBox^ txtClientName;
        System::Windows::Forms::TextBox^ txtClientPhone;
        System::Windows::Forms::Panel^ panel3;
        System::Windows::Forms::TextBox^ txtClientEmail;
        System::Windows::Forms::Panel^ panel4;
        System::Windows::Forms::TextBox^ txtClientLocation;
        System::Windows::Forms::Panel^ panel6;
        System::Windows::Forms::Button^ btn_newClient;
        System::Windows::Forms::Label^ label10;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::ComboBox^ comboCity;
        System::Windows::Forms::Panel^ panel5;

        System::ComponentModel::Container^ components;

    private:
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddClients::typeid));
            this->dataClient = (gcnew System::Windows::Forms::DataGridView());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->closeAddClients = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->txtClientName = (gcnew System::Windows::Forms::TextBox());
            this->txtClientPhone = (gcnew System::Windows::Forms::TextBox());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->txtClientEmail = (gcnew System::Windows::Forms::TextBox());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->txtClientLocation = (gcnew System::Windows::Forms::TextBox());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->btn_newClient = (gcnew System::Windows::Forms::Button());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->comboCity = (gcnew System::Windows::Forms::ComboBox());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataClient))->BeginInit();
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panel5->SuspendLayout();
            this->SuspendLayout();
            // 
            // dataClient
            // 
            this->dataClient->ColumnHeadersHeight = 29;
            this->dataClient->Location = System::Drawing::Point(0, 0);
            this->dataClient->Name = L"dataClient";
            this->dataClient->RowHeadersWidth = 51;
            this->dataClient->Size = System::Drawing::Size(240, 150);
            this->dataClient->TabIndex = 0;
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Controls->Add(this->pictureBox1);
            this->panel1->Controls->Add(this->closeAddClients);
            this->panel1->Controls->Add(this->label6);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(760, 109);
            this->panel1->TabIndex = 6;
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
            // closeAddClients
            // 
            this->closeAddClients->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->closeAddClients->BackColor = System::Drawing::Color::White;
            this->closeAddClients->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeAddClients.BackgroundImage")));
            this->closeAddClients->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->closeAddClients->FlatAppearance->BorderSize = 0;
            this->closeAddClients->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->closeAddClients->ForeColor = System::Drawing::Color::Transparent;
            this->closeAddClients->Location = System::Drawing::Point(692, -6);
            this->closeAddClients->Margin = System::Windows::Forms::Padding(0);
            this->closeAddClients->Name = L"closeAddClients";
            this->closeAddClients->Size = System::Drawing::Size(68, 79);
            this->closeAddClients->TabIndex = 1;
            this->closeAddClients->UseVisualStyleBackColor = false;
            this->closeAddClients->Click += gcnew System::EventHandler(this, &AddClients::closeAddClients_Click);
            this->closeAddClients->MouseLeave += gcnew System::EventHandler(this, &AddClients::closeAddClients_MouseLeave);
            this->closeAddClients->MouseHover += gcnew System::EventHandler(this, &AddClients::closeAddClients_MouseHover);
            // 
            // label6
            // 
            this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16.2F, System::Drawing::FontStyle::Bold));
            this->label6->Location = System::Drawing::Point(96, 35);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(101, 38);
            this->label6->TabIndex = 16;
            this->label6->Text = L"Clients";
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::White;
            this->panel2->Location = System::Drawing::Point(41, 248);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(278, 3);
            this->panel2->TabIndex = 13;
            // 
            // txtClientName
            // 
            this->txtClientName->BackColor = System::Drawing::SystemColors::Control;
            this->txtClientName->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtClientName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtClientName->ForeColor = System::Drawing::Color::Black;
            this->txtClientName->Location = System::Drawing::Point(38, 218);
            this->txtClientName->Multiline = true;
            this->txtClientName->Name = L"txtClientName";
            this->txtClientName->Size = System::Drawing::Size(295, 40);
            this->txtClientName->TabIndex = 0;
            // 
            // txtClientPhone
            // 
            this->txtClientPhone->BackColor = System::Drawing::SystemColors::Control;
            this->txtClientPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtClientPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtClientPhone->ForeColor = System::Drawing::Color::Black;
            this->txtClientPhone->Location = System::Drawing::Point(429, 211);
            this->txtClientPhone->Multiline = true;
            this->txtClientPhone->Name = L"txtClientPhone";
            this->txtClientPhone->Size = System::Drawing::Size(295, 40);
            this->txtClientPhone->TabIndex = 1;
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::White;
            this->panel3->Location = System::Drawing::Point(432, 241);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(278, 3);
            this->panel3->TabIndex = 13;
            // 
            // txtClientEmail
            // 
            this->txtClientEmail->BackColor = System::Drawing::SystemColors::Control;
            this->txtClientEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtClientEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtClientEmail->ForeColor = System::Drawing::Color::Black;
            this->txtClientEmail->Location = System::Drawing::Point(41, 332);
            this->txtClientEmail->Multiline = true;
            this->txtClientEmail->Name = L"txtClientEmail";
            this->txtClientEmail->Size = System::Drawing::Size(295, 40);
            this->txtClientEmail->TabIndex = 2;
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::White;
            this->panel4->Location = System::Drawing::Point(44, 362);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(278, 3);
            this->panel4->TabIndex = 13;
            // 
            // txtClientLocation
            // 
            this->txtClientLocation->BackColor = System::Drawing::SystemColors::Control;
            this->txtClientLocation->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtClientLocation->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtClientLocation->ForeColor = System::Drawing::Color::Black;
            this->txtClientLocation->Location = System::Drawing::Point(93, 453);
            this->txtClientLocation->Multiline = true;
            this->txtClientLocation->Name = L"txtClientLocation";
            this->txtClientLocation->Size = System::Drawing::Size(596, 40);
            this->txtClientLocation->TabIndex = 4;
            // 
            // panel6
            // 
            this->panel6->BackColor = System::Drawing::Color::White;
            this->panel6->Location = System::Drawing::Point(96, 483);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(579, 3);
            this->panel6->TabIndex = 13;
            // 
            // btn_newClient
            // 
            this->btn_newClient->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btn_newClient->BackColor = System::Drawing::Color::White;
            this->btn_newClient->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->btn_newClient->FlatAppearance->BorderSize = 0;
            this->btn_newClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_newClient->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 17, System::Drawing::FontStyle::Bold));
            this->btn_newClient->ForeColor = System::Drawing::Color::Black;
            this->btn_newClient->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_newClient.Image")));
            this->btn_newClient->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btn_newClient->Location = System::Drawing::Point(284, 567);
            this->btn_newClient->Name = L"btn_newClient";
            this->btn_newClient->Padding = System::Windows::Forms::Padding(30, 0, 0, 0);
            this->btn_newClient->Size = System::Drawing::Size(221, 69);
            this->btn_newClient->TabIndex = 5;
            this->btn_newClient->Text = L"Add";
            this->btn_newClient->UseVisualStyleBackColor = false;
            this->btn_newClient->Click += gcnew System::EventHandler(this, &AddClients::btn_newClient_Click);
            // 
            // label10
            // 
            this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
            this->label10->Location = System::Drawing::Point(39, 170);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(64, 28);
            this->label10->TabIndex = 16;
            this->label10->Text = L"Name";
            // 
            // label2
            // 
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
            this->label2->Location = System::Drawing::Point(427, 170);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(67, 28);
            this->label2->TabIndex = 16;
            this->label2->Text = L"Phone";
            // 
            // label3
            // 
            this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
            this->label3->Location = System::Drawing::Point(39, 275);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(59, 28);
            this->label3->TabIndex = 16;
            this->label3->Text = L"Email";
            // 
            // label4
            // 
            this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
            this->label4->Location = System::Drawing::Point(427, 275);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(46, 28);
            this->label4->TabIndex = 16;
            this->label4->Text = L"City";
            // 
            // label5
            // 
            this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.8F));
            this->label5->Location = System::Drawing::Point(98, 405);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(87, 28);
            this->label5->TabIndex = 16;
            this->label5->Text = L"Location";
            // 
            // comboCity
            // 
            this->comboCity->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboCity->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboCity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboCity->FormattingEnabled = true;
            this->comboCity->Items->AddRange(gcnew cli::array< System::Object^  >(27) {
                L"Alexandria", L"Cairo", L"Giza", L"Qalyubia",
                    L"Beheira", L"Gharbia", L"Monufia", L"Dakahlia", L"Kafr El Sheikh", L"Damietta", L"Port Said", L"Ismailia", L"Suez", L"North Sinai",
                    L"South Sinai", L"Sharqia", L"Beni Suef", L"Fayoum", L"Minya", L"Assiut", L"Sohag", L"Qena", L"Luxor", L"Aswan", L"Red Sea",
                    L"New Valley", L"Matrouh"
            });
            this->comboCity->Location = System::Drawing::Point(0, 0);
            this->comboCity->Name = L"comboCity";
            this->comboCity->Size = System::Drawing::Size(295, 31);
            this->comboCity->TabIndex = 17;
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->comboCity);
            this->panel5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.2F));
            this->panel5->Location = System::Drawing::Point(432, 322);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(295, 40);
            this->panel5->TabIndex = 18;
            // 
            // AddClients
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(760, 648);
            this->Controls->Add(this->panel5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->btn_newClient);
            this->Controls->Add(this->panel6);
            this->Controls->Add(this->panel4);
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->txtClientLocation);
            this->Controls->Add(this->txtClientEmail);
            this->Controls->Add(this->txtClientPhone);
            this->Controls->Add(this->txtClientName);
            this->Controls->Add(this->panel1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"AddClients";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"AddClients";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataClient))->EndInit();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panel5->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        void closeAddClients_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        void closeAddClients_MouseHover(System::Object^ sender, System::EventArgs^ e) {
            this->closeAddClients->BackColor = System::Drawing::Color::Red;
        }

        void closeAddClients_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
            this->closeAddClients->BackColor = System::Drawing::Color::White;
        }

        void btn_newClient_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ name = txtClientName->Text;
            String^ phone = txtClientPhone->Text->Trim();
            String^ email = txtClientEmail->Text->Trim();
            String^ city = comboCity->Text;
            String^ location = txtClientLocation->Text->Trim();

            if (String::IsNullOrEmpty(name) || String::IsNullOrEmpty(phone) ||
                String::IsNullOrEmpty(email) || String::IsNullOrEmpty(city) ||
                String::IsNullOrEmpty(location)) {
                MessageBox::Show("Please fill all fields!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            try {
                System::Net::Mail::MailAddress^ address = gcnew System::Net::Mail::MailAddress(email);
            }
            catch (Exception^) {
                MessageBox::Show("Please enter a valid email address!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (!System::Text::RegularExpressions::Regex::IsMatch(phone, "^[0-9]+$")) {
                MessageBox::Show("Phone number should contain only digits!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            SqlConnection^ con = Database::GetCon();
            String^ query;

            try {
                con->Open();
                if (isEditMode) {
                    query = "UPDATE clients SET name = @name, phone = @phone, email = @email, city = @city, location = @location WHERE id = @id";
                }
                else {
                    query = "INSERT INTO clients (name, phone, email, city, location) VALUES (@name, @phone, @email, @city, @location)";
                }

                SqlCommand^ cmd = gcnew SqlCommand(query, con);
                cmd->Parameters->AddWithValue("@name", name);
                cmd->Parameters->AddWithValue("@phone", phone);
                cmd->Parameters->AddWithValue("@email", email);
                cmd->Parameters->AddWithValue("@city", city);
                cmd->Parameters->AddWithValue("@location", location);

                if (isEditMode) {
                    cmd->Parameters->AddWithValue("@id", clientId);
                }

                int rowsAffected = cmd->ExecuteNonQuery();
                if (rowsAffected > 0) {
                    MessageBox::Show(isEditMode ? "Client updated successfully!" : "Client added successfully!",
                        "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                    txtClientName->Clear();
                    txtClientPhone->Clear();
                    txtClientEmail->Clear();
                    comboCity->SelectedIndex = -1;
                    txtClientLocation->Clear();

                    ClientController::LoadClients(dataGridView, editImg, delImg);
                    this->Close();
                }
                else {
                    MessageBox::Show(isEditMode ? "Failed to update client!" : "Failed to add client!",
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