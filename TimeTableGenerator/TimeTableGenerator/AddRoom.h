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
	/// Summary for AddRoom
	/// </summary>
	public ref class AddRoom : public System::Windows::Forms::Form
	{
    private:
        System::Windows::Forms::Form^ dash;
	public:
		AddRoom(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
        AddRoom(System::Windows::Forms::Form^ frm)
        {
            InitializeComponent();
            dash = frm;
        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddRoom()
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


    private: System::Windows::Forms::TextBox^ RoomNotb;
    private: System::Windows::Forms::TextBox^ Capacitytb;






    private: System::Windows::Forms::Button^ saveButton;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ RoomIDtb;

    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::ComboBox^ comboBox1;

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
            this->RoomNotb = (gcnew System::Windows::Forms::TextBox());
            this->Capacitytb = (gcnew System::Windows::Forms::TextBox());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->RoomIDtb = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(414, 50);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(175, 32);
            this->label1->TabIndex = 0;
            this->label1->Text = L"ADD ROOM";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(377, 161);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(77, 16);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Room No.  :";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(377, 211);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(67, 16);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Capacitry:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(377, 261);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(49, 16);
            this->label4->TabIndex = 3;
            this->label4->Text = L"TYPE :";
            // 
            // RoomNotb
            // 
            this->RoomNotb->Location = System::Drawing::Point(477, 161);
            this->RoomNotb->Name = L"RoomNotb";
            this->RoomNotb->Size = System::Drawing::Size(200, 22);
            this->RoomNotb->TabIndex = 6;
            // 
            // Capacitytb
            // 
            this->Capacitytb->Location = System::Drawing::Point(477, 211);
            this->Capacitytb->Name = L"Capacitytb";
            this->Capacitytb->Size = System::Drawing::Size(200, 22);
            this->Capacitytb->TabIndex = 7;
            this->Capacitytb->TextChanged += gcnew System::EventHandler(this, &AddRoom::textBox2_TextChanged);
            // 
            // saveButton
            // 
            this->saveButton->Location = System::Drawing::Point(420, 416);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(100, 30);
            this->saveButton->TabIndex = 12;
            this->saveButton->Text = L"Save";
            this->saveButton->UseVisualStyleBackColor = true;
            this->saveButton->Click += gcnew System::EventHandler(this, &AddRoom::saveButton_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(602, 423);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 13;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &AddRoom::button1_Click);
            // 
            // RoomIDtb
            // 
            this->RoomIDtb->Location = System::Drawing::Point(477, 114);
            this->RoomIDtb->Name = L"RoomIDtb";
            this->RoomIDtb->Size = System::Drawing::Size(200, 22);
            this->RoomIDtb->TabIndex = 15;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(377, 114);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(63, 16);
            this->label7->TabIndex = 14;
            this->label7->Text = L"Room ID:";
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"LAB", L"CLASS/ROOM" });
            this->comboBox1->Location = System::Drawing::Point(477, 258);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(200, 24);
            this->comboBox1->TabIndex = 16;
            // 
            // AddRoom
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1028, 490);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->RoomIDtb);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->saveButton);
            this->Controls->Add(this->Capacitytb);
            this->Controls->Add(this->RoomNotb);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AddRoom";
            this->Text = L"AddRoom";
            this->Load += gcnew System::EventHandler(this, &AddRoom::AddTeacher_Load);
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

            String^ checkquery = "SELECT COUNT (*) FROM [Room] WHERE RoomID = @RoomID";
            SqlCommand^ checkcmd = gcnew SqlCommand(checkquery, conn);
            checkcmd->Parameters->AddWithValue("@RoomID", RoomIDtb->Text);
            int count = (int)checkcmd->ExecuteScalar();

            if (count > 0) {
                MessageBox::Show("Room ID already exists", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            else {
                //is Null
                if( (RoomIDtb->Text == "") ) {
                    MessageBox::Show("Room ID is required", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    return;
                }
                else {


                    String^ query = "INSERT INTO [Room] (RoomID, RoomNumber, Capacity, Type) VALUES(@RoomID,@RoomNumber, @Capacity, @Type)";

                    SqlCommand^ cmd = gcnew SqlCommand(query, conn);


                    cmd->Parameters->AddWithValue("@RoomID", RoomIDtb->Text);
                    cmd->Parameters->AddWithValue("@RoomNumber", RoomNotb->Text);
                    cmd->Parameters->AddWithValue("@Capacity", Capacitytb->Text);
                    cmd->Parameters->AddWithValue("@Type", comboBox1->Text);
                    cmd->ExecuteNonQuery();



                    MessageBox::Show("Room added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Failed to add Room: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            conn->Close();
        }
        catch (SqlException^ ex_sql) {
			MessageBox::Show("SQL ERROR :" + ex_sql->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            conn->Close();
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
