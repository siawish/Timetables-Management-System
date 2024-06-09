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
	/// Summary for AddCourse
	/// </summary>
	public ref class AddCourse : public System::Windows::Forms::Form
	{
    private:
        System::Windows::Forms::Form^ dash;
	public:
		AddCourse(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
        AddCourse(System::Windows::Forms::Form^ frm) {
			InitializeComponent();
			dash = frm;

        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddCourse()
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

    private: System::Windows::Forms::TextBox^ CourseNametb;
    private: System::Windows::Forms::TextBox^ CourseCodetb;
    private: System::Windows::Forms::TextBox^ Descriptiontb;
    private: System::Windows::Forms::TextBox^ CreditHourstb;






    private: System::Windows::Forms::Button^ saveButton;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ CourseIDtb;

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
            this->CourseNametb = (gcnew System::Windows::Forms::TextBox());
            this->CourseCodetb = (gcnew System::Windows::Forms::TextBox());
            this->Descriptiontb = (gcnew System::Windows::Forms::TextBox());
            this->CreditHourstb = (gcnew System::Windows::Forms::TextBox());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->CourseIDtb = (gcnew System::Windows::Forms::TextBox());
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
            this->label1->Size = System::Drawing::Size(181, 32);
            this->label1->TabIndex = 0;
            this->label1->Text = L"ADD Course";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(377, 161);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(90, 16);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Course name:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(377, 211);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(89, 16);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Course Code:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(352, 261);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(120, 16);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Description (if any):";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(377, 311);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(74, 16);
            this->label5->TabIndex = 4;
            this->label5->Text = L"Credit hour:";
            // 
            // CourseNametb
            // 
            this->CourseNametb->Location = System::Drawing::Point(477, 161);
            this->CourseNametb->Name = L"CourseNametb";
            this->CourseNametb->Size = System::Drawing::Size(200, 22);
            this->CourseNametb->TabIndex = 6;
            // 
            // CourseCodetb
            // 
            this->CourseCodetb->Location = System::Drawing::Point(477, 211);
            this->CourseCodetb->Name = L"CourseCodetb";
            this->CourseCodetb->Size = System::Drawing::Size(200, 22);
            this->CourseCodetb->TabIndex = 7;
            this->CourseCodetb->TextChanged += gcnew System::EventHandler(this, &AddCourse::textBox2_TextChanged);
            // 
            // Descriptiontb
            // 
            this->Descriptiontb->Location = System::Drawing::Point(477, 261);
            this->Descriptiontb->Name = L"Descriptiontb";
            this->Descriptiontb->Size = System::Drawing::Size(200, 22);
            this->Descriptiontb->TabIndex = 8;
            // 
            // CreditHourstb
            // 
            this->CreditHourstb->Location = System::Drawing::Point(477, 311);
            this->CreditHourstb->Name = L"CreditHourstb";
            this->CreditHourstb->Size = System::Drawing::Size(200, 22);
            this->CreditHourstb->TabIndex = 9;
            // 
            // saveButton
            // 
            this->saveButton->Location = System::Drawing::Point(476, 417);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(100, 30);
            this->saveButton->TabIndex = 12;
            this->saveButton->Text = L"Save";
            this->saveButton->UseVisualStyleBackColor = true;
            this->saveButton->Click += gcnew System::EventHandler(this, &AddCourse::saveButton_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(600, 423);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 13;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &AddCourse::button1_Click);
            // 
            // CourseIDtb
            // 
            this->CourseIDtb->Location = System::Drawing::Point(477, 114);
            this->CourseIDtb->Name = L"CourseIDtb";
            this->CourseIDtb->Size = System::Drawing::Size(200, 22);
            this->CourseIDtb->TabIndex = 15;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(377, 114);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(69, 16);
            this->label7->TabIndex = 14;
            this->label7->Text = L"Course ID:";
            // 
            // AddCourse
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1028, 490);
            this->Controls->Add(this->CourseIDtb);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->saveButton);
            this->Controls->Add(this->CreditHourstb);
            this->Controls->Add(this->Descriptiontb);
            this->Controls->Add(this->CourseCodetb);
            this->Controls->Add(this->CourseNametb);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AddCourse";
            this->Text = L"Add Course";
            this->Load += gcnew System::EventHandler(this, &AddCourse::AddTeacher_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void AddTeacher_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True";
        SqlConnection^ conn = gcnew SqlConnection(connString);
        try {
            conn->Open();
            String^ query = "INSERT INTO Course (CourseID, CourseName, CourseCode, Description, CreditHours) VALUES (@CourseID, @CourseName, @CourseCode, @Description, @CreditHours)";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@CourseID", CourseIDtb->Text);
			cmd->Parameters->AddWithValue("@CourseName", CourseNametb->Text);
			cmd->Parameters->AddWithValue("@CourseCode", CourseCodetb->Text);
			cmd->Parameters->AddWithValue("@Description", Descriptiontb->Text);
			cmd->Parameters->AddWithValue("@CreditHours", CreditHourstb->Text);

            cmd->ExecuteNonQuery();

            MessageBox::Show("Course added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Failed to add "+ CourseNametb->Text+ " " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            conn->Close();
        }
    }
    private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		dash->Show();
    }
};
}
