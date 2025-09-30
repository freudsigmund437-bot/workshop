#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
	int id;
	char name[50];
	char species[50];
	int  age;
	char habitat[20];
} Animal;
char habitat[][20] = {"aquatics","savanna","jungle","river","forest"};

Animal animals[MAX] = {
	{1, "Simba", "Lion", 5, "savanna"},
	{2, "Nala", "Lion", 4, "savanna"},
	{3, "ShereKhan", "Tigre", 8, "Jungle"},
	{4, "Baloo", "Ours", 12, "forest"},
	{5, "Raja", "C	lC)phant", 15, "savanna"},
	{6, "Marty", "ZC(bre", 6, "savanna"},
	{7, "Gloria", "Hippopotame", 10, "RiviC(re"},
	{8, "Alex", "Lion", 7, "savanna"},
	{9, "Julien", "LC)murien", 3, "Jungle"},
	{10, "Melman", "Girafe", 9, "savanna"},
	{11, "Timon", "Suricate", 2, "DC)sert"},
	{12, "Pumbaa", "PhacochC(re", 5, "savanna"},
	{13, "Scar", "Lion", 11, "savanna"},
	{14, "Kaa", "Serpent", 6, "Jungle"},
	{15, "Iko", "Perroquet", 4, "Jungle"},
	{16, "Dumbo", "C	lC)phant", 3, "savanna"},
	{17, "Kiki", "Chien sauvage", 7, "savanna"},
	{18, "Donatello", "Tortue", 40, "RiviC(re"},
	{19, "Polly", "Oiseau", 5, "Jungle"},
	{20, "Kong", "Gorille", 13, "Jungle"},
};
///////////////////////////////////////////////////////////////
//function of adding Animals
///////////////////////////////////////////////////////////////
int id = 20;
void addAnimal() {
	if (id >= MAX) {
		printf("the list is already full\n");
		return;
	}

	animals[id].id = id + 1;

	printf("Name : ");
	scanf("%s", animals[id].name);

	printf("spice : ");
	scanf("%s", animals[id].species);

	printf("Age : ");
	scanf("%d", &animals[id].age);

	int habitat_choice;

	printf("Choose habitat:\n");
	printf("1. aquatics\n");
	printf("2. savanna\n");
	printf("3. jungle\n");
	printf("4. river\n");
	printf("5.forest\n");
	printf("Enter your choice (1-5): ");
	scanf("%d",&habitat_choice);
	switch (habitat_choice)
	{
	case 1:
		strcpy(animals[id].habitat, habitat[0]);
		break;
	case 2:
		strcpy(animals[id].habitat, habitat[1]);
		break;
	case 3:
		strcpy(animals[id].habitat,habitat[2]);
		break;
	case 4:
		strcpy(animals[id].habitat,habitat[3]);
		break;
	case 5:
		strcpy(animals[id].habitat,habitat[4]);
		break;
	default:
		printf("invalid input ...........\n");
		break;
	}

	id++;
	printf("the animal has been added successfully !\n");
}
///////////////////////////////////////////////////////////////
// Sort and display animals by name
///////////////////////////////////////////////////////////////
void displayAnimalsByName() {
	if (id == 0) {
		printf("There is nothing to display.\n");
		return;
	}

	for (int i = 0; i < id - 1; i++) {
		for (int j = 0; j < id - i - 1; j++) {
			if (strcmp(animals[j].name, animals[j + 1].name) > 0) {
				Animal temp = animals[j];
				animals[j] = animals[j + 1];
				animals[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < id; i++) {
		printf("ID: %d | Name: %s | EspC(ce: %s | Cge: %d | Habitat: %s\n",
		       animals[i].id, animals[i].name, animals[i].species, animals[i].age, animals[i].habitat);
	}
}
///////////////////////////////////////////////////////////////
// Sort and display animals by age
///////////////////////////////////////////////////////////////
void displayAnimalsByAge() {
	if (id == 0) {
		printf("There is nothing to display.\n");
		return;
	}

	for (int i = 0; i < id - 1; i++) {
		for (int j = 0; j < id - i - 1; j++) {
			if (animals[j].age > animals[j + 1].age) {
				Animal temp = animals[j];
				animals[j] = animals[j + 1];
				animals[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < id; i++) {
		printf("ID: %d | Name: %s | EspC(ce: %s | Cge: %d | Habitat: %s\n",
		       animals[i].id, animals[i].name, animals[i].species, animals[i].age, animals[i].habitat);
	}
}
///////////////////////////////////////////////////////////////
// display only animals from a specific habitat
///////////////////////////////////////////////////////////////
void displayAnimalsByHabitat(char habitat[50]) {
	int found = 0;
	for (int i = 0; i < id; i++) {
		if (strcmp(animals[i].habitat, habitat) == 0) {
			printf("ID: %d | Name: %s | EspC(ce: %s | Age: %d | Habitat: %s\n",
			       animals[i].id, animals[i].name, animals[i].species, animals[i].age, animals[i].habitat);
			found = 1;
		}
	}
	if (!found) {
		printf("No animals found in the habitat: %s\n", habitat);
	}
}
///////////////////////////////////////////////////////////////
// modifyAnimal();
///////////////////////////////////////////////////////////////
int main() {
	int choice,choice_of_sorting;
	do {
		printf("\n===== Animal Management System =====\n");
		printf("1. Add Animal\n");
		printf("2. Display Animals\n");
		printf("3. Modify Animal\n");
		printf("4. Delete Animal\n");
		printf("5. Search Animal\n");
		printf("6. Statistics\n");
		printf("0. Exit\n");
		printf("Choose: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addAnimal();
			break;
		case 2:
			printf("Choose sorting method:\n");
			printf("1. By Name\n");
			printf("2. By Age\n");
			printf("Enter your choice: ");
			scanf("%d", &choice_of_sorting);
			if (choice_of_sorting == 1)
			{
				displayAnimalsByName();
			} else if (choice_of_sorting == 2)
			{
				displayAnimalsByAge();
			} else {
				printf("Invalid choice!\n");
			}


			break;
		case 3:
			// modifyAnimal();
			break;
		case 4:
			// deleteAnimal();
			break;
		case 5:
			// searchAnimal();
			break;
		case 6:
			// statistics();
			break;
		case 0:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice!\n");
		}
	} while (choice != 0);
	return 0;
}