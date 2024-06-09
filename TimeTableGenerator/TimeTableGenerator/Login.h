//#pragma once
//#include "Dashboard.h"
//#include "Teacher Dash.h"
//#include "Student Dash.h"
//
//namespace TimeTableGenerator {
//
//    using namespace System;
//    using namespace System::ComponentModel;
//    using namespace System::Collections;
//    using namespace System::Windows::Forms;
//    using namespace System::Data;
//    using namespace System::Drawing;
//    using namespace System::Data::SqlClient;
//   
//
//
//    public ref class MyForm : public System::Windows::Forms::Form
//    {
//    public:
//        MyForm(void)
//        {
//            InitializeComponent();
//        }
//
//    protected:
//        ~MyForm()
//        {
//            if (components)
//            {
//                delete components;
//            }
//        }
//
//    private:
//        System::Windows::Forms::Label^ label1;
//        System::Windows::Forms::TextBox^ nametextbox;
//        System::Windows::Forms::TextBox^ passtextbox;
//        System::Windows::Forms::Button^ Loginbtn;
//        System::Windows::Forms::Label^ label2;
//        System::Windows::Forms::Label^ label3;
//        System::Windows::Forms::ComboBox^ comboBox1;
//
//        System::ComponentModel::Container^ components;
//
//#pragma region Windows Form Designer generated code
//        void InitializeComponent(void)
//        {
//            this->label1 = (gcnew System::Windows::Forms::Label());
//            this->nametextbox = (gcnew System::Windows::Forms::TextBox());
//            this->passtextbox = (gcnew System::Windows::Forms::TextBox());
//            this->Loginbtn = (gcnew System::Windows::Forms::Button());
//            this->label2 = (gcnew System::Windows::Forms::Label());
//            this->label3 = (gcnew System::Windows::Forms::Label());
//            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
//            this->SuspendLayout();
//
//            // Label1
//            this->label1->AutoSize = true;
//            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label1->Location = System::Drawing::Point(492, 78);
//            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
//            this->label1->Name = L"label1";
//            this->label1->Size = System::Drawing::Size(110, 42);
//            this->label1->TabIndex = 0;
//            this->label1->Text = L"Login";
//
//            // NameTextbox
//            this->nametextbox->Location = System::Drawing::Point(500, 149);
//            this->nametextbox->Margin = System::Windows::Forms::Padding(4);
//            this->nametextbox->Name = L"nametextbox";
//            this->nametextbox->Size = System::Drawing::Size(172, 22);
//            this->nametextbox->TabIndex = 1;
//
//            // PassTextbox
//            this->passtextbox->Location = System::Drawing::Point(500, 209);
//            this->passtextbox->Margin = System::Windows::Forms::Padding(4);
//            this->passtextbox->Name = L"passtextbox";
//            this->passtextbox->Size = System::Drawing::Size(172, 22);
//            this->passtextbox->TabIndex = 2;
//
//            // LoginButton
//            this->Loginbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->Loginbtn->Location = System::Drawing::Point(502, 351);
//            this->Loginbtn->Margin = System::Windows::Forms::Padding(4);
//            this->Loginbtn->Name = L"Loginbtn";
//            this->Loginbtn->Size = System::Drawing::Size(100, 47);
//            this->Loginbtn->TabIndex = 3;
//            this->Loginbtn->Text = L"Login";
//            this->Loginbtn->UseVisualStyleBackColor = true;
//            this->Loginbtn->Click += gcnew System::EventHandler(this, &MyForm::Loginbtn_Click);
//
//            // Label2
//            this->label2->AutoSize = true;
//            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label2->Location = System::Drawing::Point(349, 150);
//            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
//            this->label2->Name = L"label2";
//            this->label2->Size = System::Drawing::Size(86, 20);
//            this->label2->TabIndex = 4;
//            this->label2->Text = L"Username";
//
//            // Label3
//            this->label3->AutoSize = true;
//            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label3->Location = System::Drawing::Point(353, 214);
//            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
//            this->label3->Name = L"label3";
//            this->label3->Size = System::Drawing::Size(83, 20);
//            this->label3->TabIndex = 5;
//            this->label3->Text = L"Password";
//
//            // ComboBox1
//            this->comboBox1->FormattingEnabled = true;
//            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Admin", L"Teacher", L"Student" });
//            this->comboBox1->Location = System::Drawing::Point(502, 268);
//            this->comboBox1->Name = L"comboBox1";
//            this->comboBox1->Size = System::Drawing::Size(170, 24);
//            this->comboBox1->TabIndex = 6;
//
//            // MyForm
//            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
//            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//            this->ClientSize = System::Drawing::Size(1183, 539);
//            this->Controls->Add(this->comboBox1);
//            this->Controls->Add(this->label3);
//            this->Controls->Add(this->label2);
//            this->Controls->Add(this->Loginbtn);
//            this->Controls->Add(this->passtextbox);
//            this->Controls->Add(this->nametextbox);
//            this->Controls->Add(this->label1);
//            this->Margin = System::Windows::Forms::Padding(4);
//            this->Name = L"MyForm";
//            this->Text = L"Login";
//            this->ResumeLayout(false);
//            this->PerformLayout();
//        }
//#pragma endregion
//
//    private: System::Void Loginbtn_Click(System::Object^ sender, System::EventArgs^ e) {
//        String^ enteredName = nametextbox->Text;
//        String^ enteredPassword = passtextbox->Text;
//        String^ selectedUser = comboBox1->Text;
//
//        if (String::IsNullOrEmpty(enteredName) || String::IsNullOrEmpty(enteredPassword) /*|| String::IsNullOrEmpty(selectedUser)*/) {
//            MessageBox::Show("Please enter all fields!", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
//            return;
//        }
//
//        try {
//            String^ connectionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
//
//            SqlConnection^ sqlConn = gcnew SqlConnection(connectionString);
//            sqlConn->Open();
//
//            SqlCommand^ command = gcnew SqlCommand("VerifyUserLogin", sqlConn);
//            command->CommandType = CommandType::StoredProcedure;
//
//            command->Parameters->AddWithValue("@Username", enteredName);
//            command->Parameters->AddWithValue("@Password", enteredPassword);
//
//            // retrieving  foreign id (USERID ) FROM ITS RESPECTIVE TABLE
//            SqlParameter^ userTypeParam = gcnew SqlParameter("@UserType", SqlDbType::NVarChar, 10);
//            userTypeParam->Direction = ParameterDirection::Output;
//            command->Parameters->Add(userTypeParam);
//
//            SqlParameter^ foreignIdParam = gcnew SqlParameter("@ForeignID", SqlDbType::Int);
//            foreignIdParam->Direction = ParameterDirection::Output;
//            command->Parameters->Add(foreignIdParam);
//
//            command->ExecuteNonQuery();
//
//            String^ userType = userTypeParam->Value->ToString();
//
//            if (userType == selectedUser) {
//                MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
//
//                if (userType == "Admin") {
//                    Dashboard^ dash = gcnew Dashboard();
//                    dash->Show();
//                }
//                else if (userType == "Teacher") {
//                    TeacherDash^ tdash = gcnew TeacherDash();
//                    tdash->Show();
//                }
//                else if (userType == "Student") {
//                    StudentDash^ stdash = gcnew StudentDash();
//                    stdash->Show();
//                }
//                //else {
//                //    //invalid
//                //    MessageBox::Show("Unexpected user type retrieved. Please contact administrator.", "Login Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//                //}
//            }
//            else {
//                MessageBox::Show("Invalid username or password!", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
//            }
//        }
//
//        //check usename and passoword from [user] and and login to its respective user type 
//
//    /*String^ checkQuery = "SELECT COUNT(*) FROM [User] WHERE Day = @Day AND StartTime = @StartTime";*/
//
//
//
//
//
//
//    }
//    
//
//
//
//		catch (Exception^ ex) {
//			MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//		}
//        catch (SqlException^ ex) {
//            MessageBox::Show("An error occurred: " + ex->Message, "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//        }
//    }
//
//    };
//}




#pragma once
#include "Dashboard.h"
#include "Teacher Dash.h"
#include "Student Dash.h"
#include"Dashboard.h"
#include"Teacher Dash.h"

namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::TextBox^ nametextbox;
        System::Windows::Forms::TextBox^ passtextbox;
        System::Windows::Forms::Button^ Loginbtn;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->nametextbox = (gcnew System::Windows::Forms::TextBox());
            this->passtextbox = (gcnew System::Windows::Forms::TextBox());
            this->Loginbtn = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();

            // Label1
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(492, 78);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(110, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Login";

            // NameTextbox
            this->nametextbox->Location = System::Drawing::Point(500, 149);
            this->nametextbox->Margin = System::Windows::Forms::Padding(4);
            this->nametextbox->Name = L"nametextbox";
            this->nametextbox->Size = System::Drawing::Size(172, 22);
            this->nametextbox->TabIndex = 1;

            // PassTextbox
            this->passtextbox->Location = System::Drawing::Point(500, 209);
            this->passtextbox->Margin = System::Windows::Forms::Padding(4);
            this->passtextbox->Name = L"passtextbox";
            this->passtextbox->Size = System::Drawing::Size(172, 22);
            this->passtextbox->TabIndex = 2;

            // LoginButton
            this->Loginbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Loginbtn->Location = System::Drawing::Point(502, 351);
            this->Loginbtn->Margin = System::Windows::Forms::Padding(4);
            this->Loginbtn->Name = L"Loginbtn";
            this->Loginbtn->Size = System::Drawing::Size(100, 47);
            this->Loginbtn->TabIndex = 3;
            this->Loginbtn->Text = L"Login";
            this->Loginbtn->UseVisualStyleBackColor = true;
            this->Loginbtn->Click += gcnew System::EventHandler(this, &MyForm::Loginbtn_Click);

            // Label2
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(349, 150);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(86, 20);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Username";

            // Label3
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(353, 214);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(83, 20);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Password";

            // MyForm
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1183, 539);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->Loginbtn);
            this->Controls->Add(this->passtextbox);
            this->Controls->Add(this->nametextbox);
            this->Controls->Add(this->label1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MyForm";
            this->Text = L"Login";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
      

    private: System::Void Loginbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ enteredName = nametextbox->Text;
        String^ enteredPassword = passtextbox->Text;

        if (String::IsNullOrEmpty(enteredName) || String::IsNullOrEmpty(enteredPassword)) {
            MessageBox::Show("Please enter all fields!", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        try {
            String^ connectionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

            SqlConnection^ sqlConn = gcnew SqlConnection(connectionString);
            sqlConn->Open();

            SqlCommand^ command = gcnew SqlCommand("SELECT UserType, ForeignID FROM [User] WHERE Username =@Username AND Password =@Password", sqlConn);
            command->Parameters->AddWithValue("@Username", enteredName);
            command->Parameters->AddWithValue("@Password", enteredPassword);

            SqlDataReader^ reader = command->ExecuteReader();

            if (reader->Read()) {
                 String^ userType = reader["UserType"]->ToString();
                int foreignID = (int)reader["ForeignID"];

                reader->Close();
                sqlConn->Close();

                MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                if (userType == "Admin") {
                    Dashboard^ dash = gcnew Dashboard();
                    dash->Show();
                }
                else if (userType == "Teacher") {
                    TeacherDash^ tdash = gcnew TeacherDash();
                    tdash->Show();
                }
                else if (userType == "Student") {
                    StudentDash^ stdash = gcnew StudentDash();
                    stdash->Show();
                }
                
            }
            else {
                MessageBox::Show("Invalid username or password!", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }

        }
        catch (Exception^ ex) {
            MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (SqlException^ ex) {
            MessageBox::Show("An error occurred: " + ex->Message, "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    };
}
