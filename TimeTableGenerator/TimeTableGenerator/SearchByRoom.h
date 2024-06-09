#pragma once

namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class SearchByRoom : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ dash;
    public:
        SearchByRoom(void)
        {
            InitializeComponent();
            AvailableRoomIDcb();
            AvailableSectionscb();
        }

        SearchByRoom(System::Windows::Forms::Form^ obj)
        {
            InitializeComponent();
            AvailableRoomIDcb();
            AvailableSectionscb();
            dash = obj;
        }

    protected:
        ~SearchByRoom()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3; // Section Label
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ searchBySectionButton;
    private: System::Windows::Forms::ComboBox^ Roomcb;
    private: System::Windows::Forms::ComboBox^ Sectioncb; // Section ComboBox
    private: System::Windows::Forms::Button^ button1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->searchBySectionButton = (gcnew System::Windows::Forms::Button());
            this->Roomcb = (gcnew System::Windows::Forms::ComboBox());
            this->Sectioncb = (gcnew System::Windows::Forms::ComboBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(91, 95);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(66, 16);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Room ID :";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(369, 95);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(58, 16);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Section :";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(438, 35);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(240, 32);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Search By Room";
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(38, 164);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(996, 367);
            this->dataGridView1->TabIndex = 7;
            // 
            // searchBySectionButton
            // 
            this->searchBySectionButton->Location = System::Drawing::Point(535, 122);
            this->searchBySectionButton->Name = L"searchBySectionButton";
            this->searchBySectionButton->Size = System::Drawing::Size(122, 27);
            this->searchBySectionButton->TabIndex = 6;
            this->searchBySectionButton->Text = L"Search";
            this->searchBySectionButton->UseVisualStyleBackColor = true;
            this->searchBySectionButton->Click += gcnew System::EventHandler(this, &SearchByRoom::searchBySectionButton_Click);
            // 
            // Roomcb
            // 
            this->Roomcb->FormattingEnabled = true;
            this->Roomcb->Location = System::Drawing::Point(91, 125);
            this->Roomcb->Name = L"Roomcb";
            this->Roomcb->Size = System::Drawing::Size(200, 24);
            this->Roomcb->TabIndex = 5;
            // 
            // Sectioncb
            // 
            this->Sectioncb->FormattingEnabled = true;
            this->Sectioncb->Location = System::Drawing::Point(317, 125);
            this->Sectioncb->Name = L"Sectioncb";
            this->Sectioncb->Size = System::Drawing::Size(200, 24);
            this->Sectioncb->TabIndex = 11;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(676, 121);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(122, 27);
            this->button1->TabIndex = 10;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &SearchByRoom::button1_Click);
            // 
            // SearchByRoom
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1123, 534);
            this->Controls->Add(this->Sectioncb);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->searchBySectionButton);
            this->Controls->Add(this->Roomcb);
            this->Name = L"SearchByRoom";
            this->Text = L"SearchByRoom";
            this->Load += gcnew System::EventHandler(this, &SearchByRoom::SearchByRoom_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void AvailableRoomIDcb()
        {
            try
            {
                String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                SqlConnection^ conn = gcnew SqlConnection(connString);
                String^ query = "SELECT RoomID FROM Room";
                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                {
                    Roomcb->Items->Add(reader["RoomID"]->ToString());
                }
                reader->Close();
                conn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message);
            }
        }

        void AvailableSectionscb()
        {
            // This method could be expanded to dynamically fetch sections from the database if necessary
            Sectioncb->Items->AddRange(gcnew cli::array< System::Object^  >(2) { "BSE-2A", "BSE-2B" });
        }

    private: System::Void searchBySectionButton_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            if (Roomcb->SelectedItem == nullptr || Sectioncb->SelectedItem == nullptr)
            {
                MessageBox::Show("Please select both Room ID and Section.");
                return;
            }

            String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ Section = Sectioncb->SelectedItem->ToString();
            String^ query = "SELECT * FROM ["+ Section +"] WHERE RoomID = @RoomID";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);


            cmd->Parameters->AddWithValue("@RoomID", Roomcb->SelectedItem->ToString());
            
            SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
            DataTable^ dt = gcnew DataTable();
            da->Fill(dt);
            dataGridView1->DataSource = dt;
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(ex->Message);
        }
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        dash->Show();
    }

    private: System::Void SearchByRoom_Load(System::Object^ sender, System::EventArgs^ e) {
        // Perform any additional setup after loading the form
    }
    };
}
