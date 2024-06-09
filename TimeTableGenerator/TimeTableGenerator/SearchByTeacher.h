namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class SearchByTeacher : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ dash;
    public:
        SearchByTeacher(Form^ frm)
        {
            InitializeComponent();
            AvailableSectionIDcb();
            AvailableTeacherIDcb();
			dash = frm;
        }

    protected:
        ~SearchByTeacher()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::ComboBox^ Teachercb;
    private: System::Windows::Forms::ComboBox^ Sectioncb;
    private: System::Windows::Forms::Button^ searchByTeacherButton;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Button^ button1;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->Teachercb = (gcnew System::Windows::Forms::ComboBox());
               this->Sectioncb = (gcnew System::Windows::Forms::ComboBox());
               this->searchByTeacherButton = (gcnew System::Windows::Forms::Button());
               this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->button1 = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
               this->SuspendLayout();
               // 
               // Teachercb
               // 
               this->Teachercb->FormattingEnabled = true;
               this->Teachercb->Location = System::Drawing::Point(36, 116);
               this->Teachercb->Name = L"Teachercb";
               this->Teachercb->Size = System::Drawing::Size(200, 24);
               this->Teachercb->TabIndex = 0;
               // 
               // Sectioncb
               // 
               this->Sectioncb->FormattingEnabled = true;
               this->Sectioncb->Location = System::Drawing::Point(264, 116);
               this->Sectioncb->Name = L"Sectioncb";
               this->Sectioncb->Size = System::Drawing::Size(200, 24);
               this->Sectioncb->TabIndex = 1;
               // 
               // searchByTeacherButton
               // 
               this->searchByTeacherButton->Location = System::Drawing::Point(505, 116);
               this->searchByTeacherButton->Name = L"searchByTeacherButton";
               this->searchByTeacherButton->Size = System::Drawing::Size(122, 27);
               this->searchByTeacherButton->TabIndex = 2;
               this->searchByTeacherButton->Text = L"Search";
               this->searchByTeacherButton->UseVisualStyleBackColor = true;
               this->searchByTeacherButton->Click += gcnew System::EventHandler(this, &SearchByTeacher::searchByTeacherButton_Click);
               // 
               // dataGridView1
               // 
               this->dataGridView1->AllowUserToAddRows = false;
               this->dataGridView1->AllowUserToDeleteRows = false;
               this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridView1->Location = System::Drawing::Point(36, 165);
               this->dataGridView1->Name = L"dataGridView1";
               this->dataGridView1->ReadOnly = true;
               this->dataGridView1->RowHeadersVisible = false;
               this->dataGridView1->RowHeadersWidth = 51;
               this->dataGridView1->RowTemplate->Height = 24;
               this->dataGridView1->Size = System::Drawing::Size(996, 367);
               this->dataGridView1->TabIndex = 3;
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label1->Location = System::Drawing::Point(406, 38);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(272, 32);
               this->label1->TabIndex = 17;
               this->label1->Text = L"Search By Teacher";
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Location = System::Drawing::Point(94, 87);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(77, 16);
               this->label4->TabIndex = 20;
               this->label4->Text = L"Teacher ID:";
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->Location = System::Drawing::Point(327, 87);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(71, 16);
               this->label7->TabIndex = 30;
               this->label7->Text = L"Section ID:";
               // 
               // button1
               // 
               this->button1->Location = System::Drawing::Point(658, 116);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(122, 27);
               this->button1->TabIndex = 31;
               this->button1->Text = L"Close";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &SearchByTeacher::button1_Click);
               // 
               // SearchByTeacher
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1068, 556);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->label7);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->dataGridView1);
               this->Controls->Add(this->searchByTeacherButton);
               this->Controls->Add(this->Sectioncb);
               this->Controls->Add(this->Teachercb);
               this->Name = L"SearchByTeacher";
               this->Text = L"Search By Teacher";
               this->Load += gcnew System::EventHandler(this, &SearchByTeacher::SearchByTeacher_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

           void AvailableTeacherIDcb()
           {
               try
               {
                   String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                   SqlConnection^ conn = gcnew SqlConnection(connString);
                   String^ query = "SELECT TeacherID FROM Teacher";
                   SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                   conn->Open();
                   SqlDataReader^ reader = cmd->ExecuteReader();
                   while (reader->Read())
                   {
                       Teachercb->Items->Add(reader["TeacherID"]->ToString());
                   }
                   reader->Close();
                   conn->Close();
               }
               catch (Exception^ ex)
               {
                   MessageBox::Show(ex->Message);
               }
           }

           void AvailableSectionIDcb()
           {
               try
               {
                   String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                   SqlConnection^ conn = gcnew SqlConnection(connString);
                   String^ query = "SELECT SectionName FROM Sections";
                   SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                   conn->Open();
                   SqlDataReader^ reader = cmd->ExecuteReader();
                   while (reader->Read())
                   {
                       Sectioncb->Items->Add(reader["SectionName"]->ToString());
                   }
                   reader->Close();
                   conn->Close();
               }
               catch (Exception^ ex)
               {
                   MessageBox::Show(ex->Message);
               }
           }

    private: System::Void SearchByTeacher_Load(System::Object^ sender, System::EventArgs^ e)
    {
        dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dataGridView1->MultiSelect = false;
    }

    private: System::Void searchByTeacherButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ selectedTeacherID = Teachercb->SelectedItem->ToString();
        String^ selectedSectionName = Sectioncb->SelectedItem->ToString();
        String^ sectionTable = "";

        if (selectedSectionName == "BSE-2A") {
            sectionTable = "BSE-2A";
        }
        else if (selectedSectionName == "BSE-2B") {
            sectionTable = "BSE-2B";
        }

        String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
        SqlConnection^ conn = gcnew SqlConnection(connString);

        try {
            conn->Open();

            String^ query = "SELECT * FROM [" + sectionTable + "] WHERE TeacherID = @TeacherID";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@TeacherID", selectedTeacherID);

            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
            DataTable^ dt = gcnew DataTable();
            adapter->Fill(dt);

            dataGridView1->DataSource = dt;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error occurred: " + ex->Message);
        }
        finally {
            conn->Close();
        }
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        dash->Show();
    }
};
}