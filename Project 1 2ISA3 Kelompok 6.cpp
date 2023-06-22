#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<string.h>

using namespace std;

void mainmenu();
void menuOperator();
void menuMember();
void password();
void welcome();
void exitArt();

class buku{
	public:
	string kode_buku, judul_buku, Pengarang, line; 
	int tahun_terbit;
	void inputBuku(){
		cout << "\n\n\n\t\t\t  Masukan Kode Buku: ";
		getline(cin, kode_buku);
		cout << "\t\t\t  Masukan Judul Buku: ";
		getline(cin, judul_buku);
		cout << "\t\t\t  Nama Pengarang: ";
		getline(cin, Pengarang);
		cout << "\t\t\t  Masukan Tahun Terbit: ";
		cin >> tahun_terbit;
		cin.ignore();
		
		ofstream ofs;
		ofs.open("Arsip Buku.txt" , ios_base::app);
		ofs << endl;
		ofs << kode_buku << "\t #";
		ofs << judul_buku << "\t #";
		ofs << Pengarang << "\t #";
		ofs << tahun_terbit;
		
		ofs.close();
		Sleep(3000);
		system("cls");
		
	}
	void ArsipBuku(){
		int x;
		cout << "\t  |  Kode Buku\t #judul Buku\t #Pengarang\t #Tahun Terbit" << endl;
		cout << "\t  |  =======================================================================================================================" << endl;
		ifstream ifs("Arsip Buku.txt");
		while (!ifs.eof())
		{
			getline(ifs, line);
			cout << "\t  |  " << line << endl;
		}
		ifs.close();
		cout << "\n\n";
		
		cout<<"\n\t\t\t  1. Back to Member Menu";
		cout<<"\n\t\t\t  2. Back to Operator Menu";
		cout<<"\n\t\t\t  3. MAIN MENU"<<endl<<"\n\n";
		cout<<"\t\t\tINPUT : ";
		cin >> x;
		
		system("cls");
	
		if (x==1)
		{
			menuMember();
		}
	
		else if (x==2)
		{
			password();
		}
		
		else{
			mainmenu();
		}
		
	}
} *buku1, buku2;

class petugas: public buku{
	public:
	string id_petugas, nama_petugas, alamat_petugas, no_telepon_petugas, line; 
	void inputPetugas(){
		cout << "\n\n\n\t\t\t  Masukan ID petugas: ";
		getline(cin, id_petugas);
		cout << "\t\t\t  Masukan Nama Petugas: ";
		getline(cin, nama_petugas);
		cout << "\t\t\t  Masukan Alamat Petugas: ";
		getline(cin, alamat_petugas);
		cout << "\t\t\t  Masukan Nomor Telepon: ";
		getline(cin, no_telepon_petugas);
		
		ofstream ofs;
		ofs.open("Data Petugas.txt" , ios_base::app);
		ofs<<endl;
		ofs << id_petugas << "#";
		ofs << nama_petugas << "#";
		ofs << alamat_petugas << "#";
		ofs << no_telepon_petugas;
		
		ofs.close();
		Sleep(3000);
		system("cls");
		menuOperator();
		
	}
	void dataPetugas(){
		cout << "\t  |  ID Petugas\t #Nama Petugas\t #Alamat Petugas\t #Nomor Telepon Petugas" << endl;
		cout << "\t  |  =======================================================================================================================" << endl;
		ifstream ifs("Data Petugas.txt");
		while (!ifs.eof())
		{
			getline(ifs,line);
			cout << "\t  |  " << line << endl;
		}
		ifs.close();
		mainmenu();
	}
} petugas1;

class anggota: public petugas{
	public:
	string id_anggota, nama_anggota, alamat_anggota, no_telepon_anggota, line;
	void inputAnggota(){
		cout << "\n\n\n\t\t\t  Masukan ID anggota: ";
		getline(cin, id_anggota);
		cout << "\t\t\t  Masukan Nama: ";
		getline(cin, nama_anggota);
		cout << "\t\t\t  Masuka Alamat Tempat Tinggal: ";
		getline(cin, alamat_anggota);
		cout << "\t\t\t  Masukan Nomor Telepon: ";
		getline(cin, no_telepon_anggota);
		
		ofstream ofs;
		ofs.open("Data Anggota.txt" , ios_base::app);
		ofs<<endl;
		ofs << id_anggota << "#";
		ofs << nama_anggota << "#";
		ofs << alamat_anggota << "#";
		ofs << no_telepon_anggota;
		
		ofs.close();
		Sleep(3000);
		system("cls");
		menuMember();
		
	}
	void dataAnggota(){
		cout << "\t  |  ID Anggota\t #Nama Anggota\t #Alamat Anggota\t #Nomor Telepon Anggota" << endl;
		cout << "\t  |  =======================================================================================================================" << endl;
		ifstream ifs("Data Anggota.txt");
		while (!ifs.eof())
		{
			getline(ifs,line);
			cout << "\t  |  " << line << endl;
		}
		ifs.close();
		mainmenu();
	}
} anggota1;

class peminjaman: public buku{
	string kode_peminjaman, tanggal_pinjam, kode_buku[], judul_buku[], nama_peminjam, alamat_peminjam, nomor_peminjam, line;
	int jumlah;
	public:
	void inputPeminjaman(){	
		ofstream ofs;
		ofs.open("Arsip Peminjaman.txt" , ios_base::app);
		ofs<<endl;
		
		cout << "\n\n\n\t\t\t  Masukan Kode Peminjaman: ";
		getline(cin, kode_peminjaman);
		ofs << kode_peminjaman << " #";
		cout << "\t\t\t  Masukan Tanggal: ";
		getline(cin, tanggal_pinjam);
		ofs << tanggal_pinjam << " #";
		cout << "\t\t\t  Masukan Nama: ";
		getline(cin, nama_peminjam);
		ofs << nama_peminjam << " #";
		cout << "\t\t\t  Masukan Alamat Tempat Tinggal: ";
		getline(cin, alamat_peminjam);
		ofs << alamat_peminjam << " #";
		cout << "\t\t\t  Masukan Nomor Telepon: ";
		getline(cin, nomor_peminjam);
		ofs << nomor_peminjam << " #";
		cout << "\t\t\t  Masukan Jumlah Buku yang ingin Dipinjam: ";
		cin >> jumlah;
		cin.ignore();
		ofs << jumlah << " Buku #";
		cout << "\n";
		for(int i = 0; i < jumlah; i++){
			cout << "\t\t\t  Masukan Kode Buku: ";
			getline(cin, kode_buku[i]);
			ofs << kode_buku[i] << ", ";
		}
		ofs << "#";
		for(int i = 0; i < jumlah; i++){
			cout << "\t\t\t  Masukan Judul Buku: ";
			getline(cin, judul_buku[i]);
			ofs << judul_buku[i] << ", ";
		};
		
		ofs.close();
		Sleep(3000);
		system("cls");
		menuMember();
	}
	void arsipPeminjaman(){
		cout << "\t  |  Kode Peminjaman\t #Tanggal Peminjaman\t #Nama Peminjam\t #Nomor Telepon Peminjam\t #Alamat Peminjam\t #Jumlah Buku yang Dipinjam\t #Kode Buku\t #Judul Buku  " << endl;
		cout << "\t  |  =======================================================================================================================" << endl;
		ifstream ifs("Arsip Peminjaman.txt");
		while (!ifs.eof())
		{
			getline(ifs,line);
			cout << "\t  |  " << line << endl;
		}
		ifs.close();
		mainmenu();
	}
} peminjaman1;

class pengembalian: public buku{
	string kode_pengembalian, kode_peminjaman, kode_buku[], judul_buku[], tanggal_kembali, keterangan, line;
	int jumlah;
	public:
	void inputPengembalian(){
		ofstream ofs;
		ofs.open("Arsip Pengembalian.txt" , ios_base::app);
		ofs<<endl;
		
		cout << "\n\n\n\t\t\t  Masukan Kode Pengembalian: ";
		getline(cin, kode_pengembalian);
		ofs << kode_pengembalian << " #";
		cout << "\t\t\t  Masukan Kode Peminjaman: ";
		getline(cin, kode_peminjaman);
		ofs << kode_peminjaman << " #";
		cout << "\t\t\t  Masukan Tanggal Pengembalian: ";
		getline(cin, tanggal_kembali);
		ofs << tanggal_kembali << " #";
		cout << "\t\t\t  Keterangan: ";
		getline(cin, keterangan);
		ofs << keterangan << " #";
		cout << "\t\t\t  Masukan Jumlah Buku yang ingin Dikembalikan: ";
		cin >> jumlah;
		cin.ignore();
		ofs << jumlah << " Buku #";
		cout << "\n";
		for(int i = 0; i < jumlah; i++){
			cout << "\t\t\t  Masukan Kode Buku: ";
			getline(cin, kode_buku[i]);
			ofs << kode_buku[i] << ", ";	
		}
		ofs << "#";
		for(int i = 0; i < jumlah; i++){
			cout << "\t\t\t  Masukan Judul Buku: ";
			getline(cin, judul_buku[i]);
			ofs << judul_buku[i] << ", ";
		}
		
		ofs.close();
		Sleep(3000);
		system("cls");
		menuMember();
	}
	void arsipPengembalian(){
		cout << "\t  |  Kode Pengembalian\t #Kode Peminjaman\t #Tanggal Pengembalian\t #Keterangan\t #Jumlah Buku yang Dipinjam\t #Kode Buku\t #Judul Buku " << endl;
		cout << "\t  |  =======================================================================================================================" << endl;
		ifstream ifs("Arsip Pengembalian.txt");
		while (!ifs.eof())
		{
			getline(ifs,line);
			cout << "\t  |  " << line << endl;
		}
		ifs.close();
	}
} pengembalian1;

void password()
{
	system("color b");
 	string password;
   char c;
   cout << "\n\n\t\t\t PASSWORD: ";
     cin >> password;
	       if(password == "admin")
          	{
          system("cls");
	        menuOperator();
      		}	
	else
    cout<<"\n\t\t\tWrong Password.. Call Administrator";
    cout<<"\n\t\t\tReturning to Main Menu.."<<endl;
    cout<<"\n\t\t\t";
	Sleep(1000);
    cout<<"\n\t\t\tPress Enter to Continue.";
    cout<<"\n\t\t\t";
    getch();
    mainmenu();	
}

void menuOperator()
{
	int y;
	cout<<"\n\n\n\n";
	cout << endl;
	
	cout<<"\n\t\t\t  1. Daftar Operator";
	cout<<"\n\t\t\t  2. Add Book";
	cout<<"\n\t\t\t  3. List of Book";
	cout<<"\n\t\t\t  4. LOG OFF"<<endl<<"\n";
	cout<<"\t\t\tINPUT :";
	cin>>y;
	cin.ignore();
	
	
	system("cls");
	
	if(y==1){
		petugas1.inputPetugas();
	}
	
	else if(y==2){
		int jumlah;
		cout << "\n\t\t\t Masukan Jumlah Buku yang ingin Ditambahkan: ";
		cin >> jumlah;
		cin.ignore();
		buku *buku1 = new buku[jumlah];
		
		system("cls");
		
		for(int i = 0; i < jumlah; i++){
			buku1[i].inputBuku();
		}
		
		Sleep(1000);
		menuOperator();
	}
	
	else if(y==3){
		petugas1.ArsipBuku();
	}
	
	else{
		mainmenu();
	}
		
}

void menuMember()
{
	system("color f");
	int y;
	cout<<"\n\n\n\n";
	cout << endl;
	
	cout<<"\n\t\t\t  1. Daftar Anggota";
	cout<<"\n\t\t\t  2. Peminjaman";
	cout<<"\n\t\t\t  3. Pengembalian";
	cout<<"\n\t\t\t  4. List of Book";
	cout<<"\n\t\t\t  5. Main Menu"<<endl<<"\n";
	cout<<"\t\t\tINPUT :";
	cin>>y;
	cin.ignore();
	
	
	system("cls");
	
	if(y==1){
		anggota1.inputAnggota();
	}
	
	else if(y==2){
		peminjaman1.inputPeminjaman();
		
	}
	
	else if(y==3){
		pengembalian1.inputPengembalian();
	}
	
	else if(y==4){
		buku2.ArsipBuku();
	}
	
	else{
		mainmenu();
	}
		
}

void mainmenu(){
	system("color 7");
	welcome();
	int x;	
	cout << endl;
	cout<<"\n  \t\t\t  1. Operator";
	cout<<"\n  \t\t\t  2. Member";
	cout<<"\n  \t\t\t  3. EXIT" <<endl<<"\n";
	cout<<"\n  \t\t\t INPUT :";
	cin>>x;
	
	system("cls");
	
	if (x==1)
	{
		password();
	}
	
	else if (x==2)
	{
		menuMember();
	}
	
	else if(x==3)
	{
		cout << "\n\n\n\t\t\t Terima Kasih";
		Sleep(1000);
		exitArt();
	}
	
	else{
	cout << "\n\n\n \t\t\t <<< Pilihan Anda Invalid >>> ";
	Sleep(1000);
	cout << "\n \t\t\t Press Enter to Continue...";
	getch();
	mainmenu();	
	}
}

void welcome(){
	ifstream ifs ("Welcome.txt");    
	string Lines = "";
    
    if (ifs)
    {
		while (!ifs.eof ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";
	    
	    	Lines += TempLine;
		}
		
	cout << Lines;

	}
	cout<<"\n\t  |\t\t\t\t\t\t\t";
	ifs.close ();
	Sleep(2000);
}

void exitArt(){
	ifstream ifs ("Exit Thank You.txt");    
	string Lines = " ";
	cout << "\n\n\n";
    if (ifs)
    {
		while (!ifs.eof ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";
	    
	    	Lines += TempLine;
		}
		
	cout << Lines;	
	}
    cout<<"\n\t  |\t\t\t\t\t\t\t";
    ifs.close ();
    Sleep(2000);
    exit(0);
}

int main(){
	welcome();	
	int x;	
	cout << endl;
	cout<<"\n\t\t\t  1. Operator";
	cout<<"\n\t\t\t  2. Member";
	cout<<"\n\t\t\t  3. EXIT" <<endl<<"\n";
	cout<<"\n\t\t\t INPUT :";
	cin >> x;
	
	system("cls");
	
	if (x==1)
	{
		password();
	}
	
	else if (x==2)
	{
		menuMember();
	}
	
	else if(x==3)
	{
		cout << "\n\n\n\t\t\t Terima Kasih\n\n";
		Sleep(1000);
		exitArt();
		exit(0);
	}
	
	else{
	cout << "\n\n\n \t\t\t <<< Pilihan Anda Invalid >>> ";
	Sleep(1000);
	cout << "\n \t\t\t Press Enter to Continue...";
	getch();
	main();	
	}
};


