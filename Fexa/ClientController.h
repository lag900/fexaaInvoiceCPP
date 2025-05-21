//ClientController.h
#pragma once
#include "ProductCard.h"
using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
using namespace System::Drawing; 


public ref class ClientController
{

public:
  
    
    static void LoadClients(DataGridView^ dataGridView, Image^ editImg, Image^ delImg);
    static void LoadCat(DataGridView^ dataGridView, Image^ editImg, Image^ delImg);
    static void LoadProducts(DataGridView^ dataGridView, Image^ editImg, Image^ delImg, String^ searchText);
    static void LoadProductCards(FlowLayoutPanel^ flowPanel, String^ searchText);
    static void LoadOpex(DataGridView^ dataGridView);
    static void LoadAdmin(DataGridView^ dataGridView);
};


