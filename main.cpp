#include <iostream>

// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}
size_t LongueurChaine(const char* chaine){
   const char* debut=chaine;
    while(*chaine !='\0'){
        chaine++;
    }
    return chaine-debut;
}
int main(){
    char tableau[100];//declaration d un tableau de type caractere de taille max=100

    std::cout <<"entrer une chaine de caractere"<< std::endl;
    std::cin.getline(tableau, 100);//recuperation de la chaine entrer par l utilisateur et le classe dans le tableau

    size_t longueur = LongueurChaine(tableau);//appel de la fonction
    //affichage du mots entrer et calcule la longueur et convertis en chiffre
    std::cout <<"vous avez entre : "<< tableau << " qui contient : "<< static_cast<unsigned long long> (longueur) <<" caracteres."<< std::endl;

    return 0;
}
void CopierChaine(char* destination, const char* source){
    while(*source !='\0'){
        *destination = *source;
    }
    *destination='\0';
}
int main(){
    char original[100];
    char copier[100];

    std::cout <<"entrer une chaine de caractere"<< std::endl;
    std::cin.getline(original, 100);//recuperation de la chaine et la classer dans le tableau

    CopierChaine(copier, original);//appel de la fonction 
    //affiche les resultats des chaines de caractere
    std::cout <<"afficher chaine original : "<< original << std::endl;
    std::cout <<"afficher chaine copier : "<< copier << std::endl;

    return 0;
}
void ConcatenerChaines (char* destination, const char* source){
    while(*destination !='\0'){//truver la fin de destination
        destination++;
    }
    while(*source !='\0'){ //copier la source a partir de cette position
        *destination = *source;
        destination++;
        source++;
    }
    *destination ='\0';//ajouter le '\0' final
}
void ConcatenerChaines (char* destination, const char* source){
    while(*destination !='\0'){//truver la fin de destination
        destination++;
    }
    while(*source !='\0'){ //copier la source a partir de cette position
        *destination = *source;
        destination++;
        source++;
    }
    *destination ='\0';//ajouter le '\0' final
}
int main(){
    char texte[100]="bonjour";
    const char* ajout="tout le monde !";

    ConcatenerChaines(texte, ajout);
    std::cout << texte << std::endl;// affiche le texte qui est bonjour tout le monde!

    return 0;
}
char* TrouverCaractere(const char* chaine, char caractere){
    while(caractere !='\0'){
        if(caractere = chaine){
           char* chaine;
        }else{
            return nullptr;
        }
    }
}
int main(){
    char tableau[100];

    std::cout <<"entrer une chaine de caractere"<< std::endl;
    std::cin.getline(tableau, 100);

    char caractere = TrouverCaractere(tableau);

    std::cout <<"vous avez entrer : "<< tableau << std::endl;

    return 0;
}
char* TrouverCaractere(const char* chaine, char caractere){
    while(caractere !='\0'){
        if(caractere = chaine){
           char* chaine;
        }else{
            return nullptr;
        }
    }
}
int main(){
    char tableau[100];

    std::cout <<"entrer une chaine de caractere"<< std::endl;
    std::cin.getline(tableau, 100);

    char caractere = TrouverCaractere(tableau);

    std::cout <<"vous avez entrer : "<< tableau << std::endl;

    return 0;
}
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille){
    unsigned char* zonechar=(unsigned char*)zone;
    for(i=o; taille>i; i++){
        zonechar[i] = valeur;
    }
}
int main(){
    char tableau[10];//declaration d un tableau de taille 10

    InitialiserMemoire(tableau,'A', 10);//remplir le tableau avec la valeur de A

    std::cout <<"afficher contenue du tableau : "<< std::endl;
    for(int i=0; i<10; i++){
        std::cout << tableaux[i] <<''<< std::endl;
    }
    return 0;
}
int ComparerChaines(const char* chaine1, const char* chaine2){
    while(*chaine1 !='\0' && *chaine2 !='\0'){
        chaine1++;
        chaine2++;
    }
    return *chaine1-*chaine2;
}
int main(){
    const char* chaine1;
    const char* chaine2;

    std::cout <<"entrer la premiere chaine de caractere"<< std::endl;
    std::cin >>chaine1;//recuperation de la chaine entrer par l utilisateur
    std::cout <<"entre la deuxieme chaine de caractere"<< std::endl;
    std::cin >>chaine2;//recuperation de la chaine entrer par l utilisateur

    int resultats= ComparerChaines(chaine1, chaine2);//appel de la fonction
    
    //boucle pour comparer et afficher le resultat
    if(resultats==0){
        std::cout <<"les deux chaines sont identiques"<< std::endl;
    }else if(resultats<0){
        std::cout <<"premiere < deuxieme"<< std::endl;
    }else{
        std::cout <<"premiere > deuxieme"<< std::endl;
    }
    return 0;
}
void ConvertirMinuscules(char* chaine){
    while(*chaine){
        if(*chaine >='A' && *chaine <='Z')*chaine += 32;
        chaine++;
    }
}
int main(){
    char texte[]="BONJOUR A TOUS";
    ConvertirMinuscules(texte);//appel de la fonction
    std::cout << texte <<"\n"<< std::endl;//affiche le texte 
    std::cout <<"traitement termine"<< std::endl;//affiche le texte deja convertis en minuscule

    return 0;
}
