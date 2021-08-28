#pragma once
#include "Compression.h"
#include "HaffmanTree.h"
#include "fstream"
#include <vcclr.h>
#include <ctime>
#include "PropertiesForm.h"
#include "checkingThePath.h"
#include "AnalysisForm.h"
namespace КурсоваяРаботаархиватор {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  CompressButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  UncompressButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  ExitButton;
	private: System::Windows::Forms::ToolStripMenuItem^  алгоритмToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  HaffmanCheckBox;
	private: System::Windows::Forms::ToolStripMenuItem^  RLECheckBox;

	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  propertiesButton;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteButton;
	private: System::Windows::Forms::ToolStripMenuItem^  rescanDrives;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::TreeView^  treeView2;
	private: System::Windows::Forms::ToolStripMenuItem^  CompressButton2;
	private: System::Windows::Forms::ToolStripMenuItem^  UncompressButton2;
	private: System::Windows::Forms::ToolStripMenuItem^  анализToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  статистическийАнализToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::Label^  label1;

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CompressButton1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->UncompressButton1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->алгоритмToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HaffmanCheckBox = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RLECheckBox = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->анализToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->статистическийАнализToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->CompressButton2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->UncompressButton2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rescanDrives = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->propertiesButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->treeView2 = (gcnew System::Windows::Forms::TreeView());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->CheckFileExists = false;
			this->openFileDialog1->InitialDirectory = L"C:\\Users\\Артём.DESKTOP-RE43EN0\\Desktop\\ТиМП (ТехнологииИМетодыПрограммирования)\\К" 
				L"урсоваяРабота(архиватор)";
			this->openFileDialog1->Title = L"Выберите файл для сжатия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(616, 21);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Выберите путь для открытия файла и путь для сохранения в разных окнах:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->файлToolStripMenuItem, 
				this->алгоритмToolStripMenuItem, this->анализToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->CompressButton1, 
				this->UncompressButton1, this->ExitButton});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// CompressButton1
			// 
			this->CompressButton1->Enabled = false;
			this->CompressButton1->Name = L"CompressButton1";
			this->CompressButton1->Size = System::Drawing::Size(164, 22);
			this->CompressButton1->Text = L"Сжатие";
			this->CompressButton1->Click += gcnew System::EventHandler(this, &Form1::CompressButton_Click);
			// 
			// UncompressButton1
			// 
			this->UncompressButton1->Enabled = false;
			this->UncompressButton1->Name = L"UncompressButton1";
			this->UncompressButton1->Size = System::Drawing::Size(164, 22);
			this->UncompressButton1->Text = L"Восстановление";
			this->UncompressButton1->Click += gcnew System::EventHandler(this, &Form1::UncompressButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(164, 22);
			this->ExitButton->Text = L"Выход";
			this->ExitButton->Click += gcnew System::EventHandler(this, &Form1::ExitButton_Click);
			// 
			// алгоритмToolStripMenuItem
			// 
			this->алгоритмToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->HaffmanCheckBox, 
				this->RLECheckBox});
			this->алгоритмToolStripMenuItem->Name = L"алгоритмToolStripMenuItem";
			this->алгоритмToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->алгоритмToolStripMenuItem->Text = L"Алгоритм";
			// 
			// HaffmanCheckBox
			// 
			this->HaffmanCheckBox->Checked = true;
			this->HaffmanCheckBox->CheckOnClick = true;
			this->HaffmanCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->HaffmanCheckBox->Name = L"HaffmanCheckBox";
			this->HaffmanCheckBox->Size = System::Drawing::Size(121, 22);
			this->HaffmanCheckBox->Text = L"Haffman";
			this->HaffmanCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::HaffmanCheckBox_CheckedChanged);
			// 
			// RLECheckBox
			// 
			this->RLECheckBox->CheckOnClick = true;
			this->RLECheckBox->Name = L"RLECheckBox";
			this->RLECheckBox->Size = System::Drawing::Size(121, 22);
			this->RLECheckBox->Text = L"RLE";
			this->RLECheckBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::RLECheckBox_CheckedChanged);
			// 
			// анализToolStripMenuItem
			// 
			this->анализToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->статистическийАнализToolStripMenuItem});
			this->анализToolStripMenuItem->Name = L"анализToolStripMenuItem";
			this->анализToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->анализToolStripMenuItem->Text = L"Анализ";
			// 
			// статистическийАнализToolStripMenuItem
			// 
			this->статистическийАнализToolStripMenuItem->Name = L"статистическийАнализToolStripMenuItem";
			this->статистическийАнализToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->статистическийАнализToolStripMenuItem->Text = L"Статистический анализ";
			this->статистическийАнализToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::статистическийАнализToolStripMenuItem_Click);
			// 
			// treeView1
			// 
			this->treeView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->treeView1->ContextMenuStrip = this->contextMenuStrip1;
			this->treeView1->HideSelection = false;
			this->treeView1->HotTracking = true;
			this->treeView1->Indent = 19;
			this->treeView1->Location = System::Drawing::Point(0, 0);
			this->treeView1->Name = L"treeView1";
			this->treeView1->ShowNodeToolTips = true;
			this->treeView1->ShowPlusMinus = false;
			this->treeView1->ShowRootLines = false;
			this->treeView1->Size = System::Drawing::Size(374, 474);
			this->treeView1->TabIndex = 11;
			this->treeView1->AfterExpand += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterExpand);
			this->treeView1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::treeView1_MouseDown);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->CompressButton2, 
				this->UncompressButton2, this->deleteButton, this->rescanDrives, this->propertiesButton});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(165, 114);
			// 
			// CompressButton2
			// 
			this->CompressButton2->Enabled = false;
			this->CompressButton2->Name = L"CompressButton2";
			this->CompressButton2->Size = System::Drawing::Size(164, 22);
			this->CompressButton2->Text = L"Сжатие";
			this->CompressButton2->Click += gcnew System::EventHandler(this, &Form1::CompressButton_Click);
			// 
			// UncompressButton2
			// 
			this->UncompressButton2->Enabled = false;
			this->UncompressButton2->Name = L"UncompressButton2";
			this->UncompressButton2->Size = System::Drawing::Size(164, 22);
			this->UncompressButton2->Text = L"Восстановление";
			this->UncompressButton2->Click += gcnew System::EventHandler(this, &Form1::UncompressButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(164, 22);
			this->deleteButton->Text = L"Удалить";
			this->deleteButton->Click += gcnew System::EventHandler(this, &Form1::deleteButton_Click);
			// 
			// rescanDrives
			// 
			this->rescanDrives->Name = L"rescanDrives";
			this->rescanDrives->Size = System::Drawing::Size(164, 22);
			this->rescanDrives->Text = L"Обновить";
			this->rescanDrives->Click += gcnew System::EventHandler(this, &Form1::rescanDrives_Click);
			// 
			// propertiesButton
			// 
			this->propertiesButton->Name = L"propertiesButton";
			this->propertiesButton->Size = System::Drawing::Size(164, 22);
			this->propertiesButton->Text = L"Свойства";
			this->propertiesButton->Click += gcnew System::EventHandler(this, &Form1::propertiesButton_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"root.png");
			this->imageList1->Images->SetKeyName(1, L"file2.png");
			this->imageList1->Images->SetKeyName(2, L"folder.png");
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->Location = System::Drawing::Point(12, 55);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->treeView1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->treeView2);
			this->splitContainer1->Size = System::Drawing::Size(754, 474);
			this->splitContainer1->SplitterDistance = 374;
			this->splitContainer1->TabIndex = 13;
			// 
			// treeView2
			// 
			this->treeView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->treeView2->ContextMenuStrip = this->contextMenuStrip1;
			this->treeView2->HideSelection = false;
			this->treeView2->HotTracking = true;
			this->treeView2->Indent = 19;
			this->treeView2->Location = System::Drawing::Point(0, 0);
			this->treeView2->Name = L"treeView2";
			this->treeView2->ShowNodeToolTips = true;
			this->treeView2->ShowPlusMinus = false;
			this->treeView2->ShowRootLines = false;
			this->treeView2->Size = System::Drawing::Size(376, 474);
			this->treeView2->TabIndex = 12;
			this->treeView2->AfterExpand += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterExpand);
			this->treeView2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::treeView1_MouseDown);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker2_DoWork);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker2_RunWorkerCompleted);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label1->Location = System::Drawing::Point(264, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(262, 24);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Идёт процесс архивирования...";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 541);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Алгоритмы сжатия данных";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Compression^ arch;
	int time;
	checkingThePath^ ctp;//форма для проверки путей
	System::Windows::Forms::TreeView ^ curTreeView, ^secondTreeView;
	private: void ScanDrives()
			 {
				 treeView1->Nodes->Clear();
				 treeView2->Nodes->Clear();
				 for each (System::IO::DriveInfo^ drive in System::IO::DriveInfo::GetDrives())
				 {
					 System::IO::DirectoryInfo^ rootFolder=gcnew System::IO::DirectoryInfo(drive->Name);
					 if(rootFolder->Exists==true)
					 {
						 TreeNode^ rootNode=gcnew TreeNode(drive->Name);
						 rootNode->SelectedImageIndex=0;
						 rootNode->ImageIndex=0;
						 rootNode->Name="Folder";
						 treeView1->Nodes->Add(rootNode);
						 BuildTree(rootFolder, rootNode->Nodes);
						 treeView2->Nodes->Add((TreeNode^)rootNode->Clone());
					 }
				 }
			 }
	private: void BuildTree(System::IO::DirectoryInfo^ directoryInfo, TreeNodeCollection^ curNode)
			 {
				 try
				 {
					 for each (System::IO::DirectoryInfo^ subdir in directoryInfo->GetDirectories())
					 {
						 bool test=true;//тест на существование папки(чтобы не добавлять одну и ту же папку)
						 for each(TreeNode^ node in curNode)
						 {
							 if(node->Name=="Folder"&&node->Text==subdir->Name) {test=false; break;} 
						 }
						 if(test/*если тест прошёл успешно*/) 
						 {
							 TreeNode^ node=gcnew TreeNode(subdir->Name);
							 node->SelectedImageIndex=2;
							 node->ImageIndex=2;
							 node->Name="Folder";
							 curNode->Add(node);
						 }
					 }
					 //Перебираем файлы
					 for each (System::IO::FileInfo^ file in directoryInfo->GetFiles())
					 {
						 //Добавляем новый узел в коллекцию Nodes
						 //С именем текущей директории и указанием ключа 
						 //со значением "File".
						 bool test=true;//тест на существование файла(чтобы не добавлять один и тот же файл)
						 for each(TreeNode^ node in curNode)
						 {
							 if(node->Name=="File"&&node->Text==file->Name) {test=false; break;} 
						 }
						 if(test/*если тест прошёл успешно*/) 
						 {
							 TreeNode^ node=gcnew TreeNode(file->Name);
							 node->SelectedImageIndex=1;
							 node->ImageIndex=1;
							 node->Name="File";
							 curNode->Add(node);
						 }
					 }
				 }
				 catch(System::UnauthorizedAccessException^)
				 {
					 //при отказе доступа к данным
					 //MessageBox::Show("Отказанно в доступе к системным данным!", "Добавление вершины дерева", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 //return;
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 arch=gcnew Compression();
				 treeView1->ImageList=imageList1;
				 treeView2->ImageList=imageList1;
				 ScanDrives();
			 }

	private: System::Void HaffmanCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(HaffmanCheckBox->Checked==true)
				 {
					 RLECheckBox->Checked=false;
					 //KWECheckBox->Checked=false;
				 }
			 }
	private: System::Void RLECheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(RLECheckBox->Checked)
				 {
					 HaffmanCheckBox->Checked=false;
					 //KWECheckBox->Checked=false;
				 }
			 }
	

	private: System::Void CompressButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(HaffmanCheckBox->Checked) arch->ChangeAlgorithm(Algorithm_Haffman);
				 else if(RLECheckBox->Checked) arch->ChangeAlgorithm(Algorithm_RLE);
				 else 
				 {
					 MessageBox::Show("Выберите один из алгоритмов для сжатия!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 return;
				 }
				 ctp=gcnew checkingThePath(treeView1->SelectedNode->FullPath, treeView2->SelectedNode->FullPath+"\\"+treeView1->SelectedNode->Text+".arch");
				 ctp->ShowDialog();
				 //time=Clock();
				 label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 label1->Text="Идёт процесс архивирования...";
				 label1->Visible=true;
				 //label1->Refresh();
				 backgroundWorker1->RunWorkerAsync();
				 //if(arch->Compress(ctp->openFileName, ctp->saveFileName)==false) 
				 //{
				//	 MessageBox::Show("Неверный файл или ошибка доступа", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				//	 return;
				 //}
				 //time=Clock()-time;
				 
			 }
	private: System::Void UncompressButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(HaffmanCheckBox->Checked) arch->ChangeAlgorithm(Algorithm_Haffman);
				 else if(RLECheckBox->Checked) arch->ChangeAlgorithm(Algorithm_RLE);
				 //else if(KWECheckBox->Checked) arch->ChangeAlgorithm(Algorithm_KWE);
				 else 
				 {
					 MessageBox::Show("Выберите один из алгоритмов для восстановления!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 return;
				 }
				 ctp=gcnew checkingThePath(treeView1->SelectedNode->FullPath, treeView2->SelectedNode->FullPath+"\\"+treeView1->SelectedNode->Text);
				 ctp->ShowDialog();
				 label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 label1->Text="Идёт процесс восстановления...";
				 label1->Visible=true;
				 backgroundWorker2->RunWorkerAsync();
			 }
	private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }

	private: System::Void treeView1_AfterExpand(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
			 //происходит после раскрытия узла
			 try
			 {
				 System::IO::Directory::GetDirectories(e->Node->FullPath);
			 }
			 catch(System::UnauthorizedAccessException^)
			 {
				 //при отказе доступа к данным
				 MessageBox::Show("Отказанно в доступе к системным данным!", "Добавление вершины дерева", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
			 for each(TreeNode^ Node in e->Node->Nodes)
			 {
				 if(Node->Name=="Folder") BuildTree(gcnew System::IO::DirectoryInfo(Node->FullPath), Node->Nodes);
			 }
		 }
	private: System::Void treeView1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 curTreeView=((System::Windows::Forms::TreeView^)sender);
				 if(curTreeView==treeView1) secondTreeView=treeView2;
				 else secondTreeView=treeView1;
				 curTreeView->SelectedNode=curTreeView->GetNodeAt(e->X, e->Y);
				 if(curTreeView->SelectedNode==nullptr) return;
				 if(curTreeView->SelectedNode->Name=="File")//если выбран файл, открываем доступ к функции архивирования
				 {
					 CompressButton1->Enabled=true;
					 CompressButton2->Enabled=true;
				 }
				 else
				 {
					 CompressButton1->Enabled=false;
					 CompressButton2->Enabled=false;
					 curTreeView->SelectedNode->Nodes->Clear();
					 BuildTree(gcnew System::IO::DirectoryInfo(curTreeView->SelectedNode->FullPath), curTreeView->SelectedNode->Nodes);
				 }
				 std::ifstream file;
				 pin_ptr<const wchar_t> name=PtrToStringChars(curTreeView->SelectedNode->FullPath);
				 file.open(name, std::ios::binary);
				 int temp;
				 //если файл является архивом, созданным в этой программе, открываем доступ к функции восстановления
				 if(file.get()==46&&file.get()==97&&file.get()==114&&file.get()==99&&file.get()==104&&(temp=file.get())<=2&&temp>=0)
				 {
					 UncompressButton1->Enabled=true;
					 UncompressButton2->Enabled=true;
				 }
				 else
				 {
					 UncompressButton1->Enabled=false;
					 UncompressButton2->Enabled=false;
				 }
				 file.close();
			 }
	private: System::Void rescanDrives_Click(System::Object^  sender, System::EventArgs^  e) {
				 //ScanDrives();
				 TreeNode^ currentFolderNode;
				 TreeView^ currentTreeView;
				 if(splitContainer1->ActiveControl==treeView1) currentTreeView=treeView1;
				 else currentTreeView=treeView2;
				 if(currentTreeView->SelectedNode->Name=="Folder") currentFolderNode=currentTreeView->SelectedNode;//если нажали на папку
				 else currentFolderNode=currentTreeView->SelectedNode->Parent;//если нажали на файл
				 currentFolderNode->Nodes->Clear();
				 BuildTree(gcnew System::IO::DirectoryInfo(currentFolderNode->FullPath), currentFolderNode->Nodes);
			 }
	private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 try
				 {
					 if(MessageBox::Show("Вы действительно хотите безразвратно удалить "+curTreeView->SelectedNode->Text+"?", "Удаление", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning)==System::Windows::Forms::DialogResult::OK) 
						 (gcnew System::IO::FileInfo(curTreeView->SelectedNode->FullPath))->Delete();
				 }
				 catch(System::UnauthorizedAccessException^)
				 {
					  MessageBox::Show("Отказанно в доступе к системным данным!", "Удаление", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }
	
	private: System::Void propertiesButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 PropertiesForm^ pf=gcnew PropertiesForm(curTreeView->SelectedNode->Name, curTreeView->SelectedNode->FullPath);
				 pf->Show();
			 }
	private: System::Void статистическийАнализToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 AnalysisForm^ af=gcnew AnalysisForm();
				 af->Show();
			 }

private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 if(arch->Compress(ctp->openFileName, ctp->saveFileName)==false) 
			 {
				 MessageBox::Show("Неверный файл или ошибка доступа", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
		}
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 if(arch->Uncompress(ctp->openFileName, ctp->saveFileName)==false) 
			 {
				 MessageBox::Show("Неверный файл или ошибка доступа", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
			 //treeView1->SelectedNode->Nodes->Clear();
			 //BuildTree(gcnew System::IO::DirectoryInfo(treeView1->SelectedNode->Parent->FullPath), treeView1->SelectedNode->Nodes);
			 //treeView2->SelectedNode->Nodes->Clear();
			 //BuildTree(gcnew System::IO::DirectoryInfo(treeView2->SelectedNode->FullPath), treeView2->SelectedNode->Nodes);
		 }
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 for(int green=label1->BackColor.G, blue=label1->BackColor.B; green<256; green++)
			 {
				 if(blue>0) blue--;
				 label1->BackColor=System::Drawing::Color::FromArgb(255, label1->BackColor.R, green, blue);
				 int timer=clock();
				 while(clock()-timer<40){}
				 label1->Refresh();
			 }
			 label1->Text="Архивирование завершено!";
		 }
private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 for(int green=label1->BackColor.G, blue=label1->BackColor.B; green<256; green++)
			 {
				 if(blue>0) blue--;
				 label1->BackColor=System::Drawing::Color::FromArgb(255, label1->BackColor.R, green, blue);
				 int timer=clock();
				 while(clock()-timer<40){}
				 label1->Refresh();
			 }
			 label1->Text="Восстановление завершено!";
		 }
};
}

