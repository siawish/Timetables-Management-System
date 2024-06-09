#pragma once

namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    /// <summary>
    /// Summary for AddTeacher
    /// </summary>
    public ref class AddTeacher : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ dash;
    public:
        AddTeacher(void)
        {
            InitializeComponent();
        }
		AddTeacher(System::Windows::Forms::Form^ frm)
        {
			InitializeComponent();
			dash = frm;
		}

    protected:
        ~AddTeacher()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::TextBox^ Usernametb;
    private: System::Windows::Forms::TextBox^ Passwordtb;
    private: System::Windows::Forms::TextBox^ Fnametb;
    private: System::Windows::Forms::TextBox^ LastNametb;
    private: System::Windows::Forms::TextBox^ Emailtb;

    private: System::Windows::Forms::Button^ saveButton;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ TeacherIDtb;
    private: System::Windows::Forms::Label^ label7;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->Usernametb = (gcnew System::Windows::Forms::TextBox());
            this->Passwordtb = (gcnew System::Windows::Forms::TextBox());
            this->Fnametb = (gcnew System::Windows::Forms::TextBox());
            this->LastNametb = (gcnew System::Windows::Forms::TextBox());
            this->Emailtb = (gcnew System::Windows::Forms::TextBox());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->TeacherIDtb = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(414, 50);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(225, 32);
            this->label1->TabIndex = 0;
            this->label1->Text = L"ADD TEACHER";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(377, 161);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(73, 16);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Username:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(377, 211);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(70, 16);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Password:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(377, 261);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(75, 16);
            this->label4->TabIndex = 3;
            this->label4->Text = L"First Name:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(377, 311);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(75, 16);
            this->label5->TabIndex = 4;
            this->label5->Text = L"Last Name:";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(377, 361);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(44, 16);
            this->label6->TabIndex = 5;
            this->label6->Text = L"Email:";
            // 
            // Usernametb
            // 
            this->Usernametb->Location = System::Drawing::Point(477, 161);
            this->Usernametb->Name = L"Usernametb";
            this->Usernametb->Size = System::Drawing::Size(200, 22);
            this->Usernametb->TabIndex = 6;
            // 
            // Passwordtb
            // 
            this->Passwordtb->Location = System::Drawing::Point(477, 211);
            this->Passwordtb->Name = L"Passwordtb";
            this->Passwordtb->Size = System::Drawing::Size(200, 22);
            this->Passwordtb->TabIndex = 7;
            this->Passwordtb->TextChanged += gcnew System::EventHandler(this, &AddTeacher::textBox2_TextChanged);
            // 
            // Fnametb
            // 
            this->Fnametb->Location = System::Drawing::Point(477, 261);
            this->Fnametb->Name = L"Fnametb";
            this->Fnametb->Size = System::Drawing::Size(200, 22);
            this->Fnametb->TabIndex = 8;
            // 
            // LastNametb
            // 
            this->LastNametb->Location = System::Drawing::Point(477, 311);
            this->LastNametb->Name = L"LastNametb";
            this->LastNametb->Size = System::Drawing::Size(200, 22);
            this->LastNametb->TabIndex = 9;
            // 
            // Emailtb
            // 
            this->Emailtb->Location = System::Drawing::Point(477, 361);
            this->Emailtb->Name = L"Emailtb";
            this->Emailtb->Size = System::Drawing::Size(200, 22);
            this->Emailtb->TabIndex = 10;
            // 
            // saveButton
            // 
            this->saveButton->Location = System::Drawing::Point(476, 417);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(100, 30);
            this->saveButton->TabIndex = 12;
            this->saveButton->Text = L"Save";
            this->saveButton->UseVisualStyleBackColor = true;
            this->saveButton->Click += gcnew System::EventHandler(this, &AddTeacher::saveButton_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(600, 423);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 13;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &AddTeacher::button1_Click);
            // 
            // TeacherIDtb
            // 
            this->TeacherIDtb->Location = System::Drawing::Point(477, 114);
            this->TeacherIDtb->Name = L"TeacherIDtb";
            this->TeacherIDtb->Size = System::Drawing::Size(200, 22);
            this->TeacherIDtb->TabIndex = 15;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(377, 114);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(77, 16);
            this->label7->TabIndex = 14;
            this->label7->Text = L"Teacher ID:";
            // 
            // AddTeacher
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1028, 490);
            this->Controls->Add(this->TeacherIDtb);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->saveButton);
            this->Controls->Add(this->Emailtb);
            this->Controls->Add(this->LastNametb);
            this->Controls->Add(this->Fnametb);
            this->Controls->Add(this->Passwordtb);
            this->Controls->Add(this->Usernametb);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AddTeacher";
            this->Text = L"AddTeacher";
            this->Load += gcnew System::EventHandler(this, &AddTeacher::AddTeacher_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void AddTeacher_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

        SqlConnection^ conn = gcnew SqlConnection(connString);
        try {
            conn->Open();
            //CHECK TEACHER ALREADY EXISTS
            String^ checkquery = "SELECT COUNT(*) FROM [Teacher] WHERE TeacherID = @TeacherID";
            SqlCommand^ checkcmd = gcnew SqlCommand(checkquery, conn);
            checkcmd->Parameters->AddWithValue("@TeacherID", TeacherIDtb->Text);
            int count = (int)checkcmd->ExecuteScalar();

            if (count > 0) {
                MessageBox::Show("Teacher ID exists", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            else {


                String^ query = "INSERT INTO [Teacher] (TeacherID, FirstName, LastName, Email) VALUES (@TeacherID, @FirstName, @LastName, @Email)";
                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                String^ query1 = "INSERT INTO [User] (Username, Password, UserType, ForeignID) VALUES (@Username , @Password ,@UserType, @ForeignID)";

                SqlCommand^ add = gcnew SqlCommand(query1, conn);
                cmd->Parameters->AddWithValue("@TeacherID", TeacherIDtb->Text);
                cmd->Parameters->AddWithValue("@FirstName", Fnametb->Text);
                cmd->Parameters->AddWithValue("@LastName", LastNametb->Text);
                cmd->Parameters->AddWithValue("@Email", Emailtb->Text);
                cmd->ExecuteNonQuery(); // Execute the first command

                add->Parameters->AddWithValue("@Username", Usernametb->Text);
                add->Parameters->AddWithValue("@Password", Passwordtb->Text);
                add->Parameters->AddWithValue("@UserType", "Teacher");
                add->Parameters->AddWithValue("@ForeignID", TeacherIDtb->Text->ToString());
                add->ExecuteNonQuery(); // Execute the second command

                MessageBox::Show("Teacher added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Failed to add teacher: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            conn->Close(); // Ensure connection is closed
        }
    }

    private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		dash->Show();
    }
};
}
