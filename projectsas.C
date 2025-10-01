#include <stdio.h>

#include <string.h>

#define MAX 100

typedef struct {
   int id;
   char name[50];
   char species[50];
   int age;
   char habitat[50];
}
Animal;

char habitat[][20] = {
   "aquatics",
   "savanna",
   "jungle",
   "river",
   "forest"
};

Animal animals[MAX] = {
   {
      1,
      "Simba",
      "Lion",
      5,
      "savanna"
   },
   {
      2,
      "Nala",
      "Lion",
      4,
      "savanna"
   },
   {
      3,
      "ShereKhan",
      "Tigre",
      8,
      "jungle"
   },
   {
      4,
      "Baloo",
      "Ours",
      12,
      "forest"
   },
   {
      5,
      "Raja",
      "Elephant",
      15,
      "savanna"
   },
   {
      6,
      "Marty",
      "Zebre",
      6,
      "savanna"
   },
   {
      7,
      "Gloria",
      "Hippopotame",
      10,
      "river"
   },
   {
      8,
      "Alex",
      "Lion",
      7,
      "savanna"
   },
   {
      9,
      "Julien",
      "Lemurien",
      3,
      "jungle"
   },
   {
      10,
      "Melman",
      "Girafe",
      9,
      "savanna"
   },
   {
      11,
      "Timon",
      "Suricate",
      2,
      "desert"
   },
   {
      12,
      "Pumbaa",
      "Phacochere",
      5,
      "savanna"
   },
   {
      13,
      "Scar",
      "Lion",
      11,
      "savanna"
   },
   {
      14,
      "Kaa",
      "Serpent",
      6,
      "jungle"
   },
   {
      15,
      "Iko",
      "Perroquet",
      4,
      "jungle"
   },
   {
      16,
      "Dumbo",
      "Elephant",
      3,
      "savanna"
   },
   {
      17,
      "Kiki",
      "Chien sauvage",
      7,
      "savanna"
   },
   {
      18,
      "Donatello",
      "Tortue",
      40,
      "river"
   },
   {
      19,
      "Polly",
      "Oiseau",
      5,
      "jungle"
   },
   {
      20,
      "Kong",
      "Gorille",
      13,
      "jungle"
   },

};
///////////////////////////////////////////////////////////////
//function of adding Animals
///////////////////////////////////////////////////////////////
int id = 20;
void addAnimal() {
   char continue_adding;

   do {
      if (id >= MAX) {
         printf("The list is already full\n");
      }

      animals[id].id = id + 1;

      printf("Name : ");
      scanf("%s", animals[id].name);

      printf("spice : ");
      scanf("%s", animals[id].species);

      printf("Age : ");
      scanf("%d", & animals[id].age);

      int habitat_choice;

      printf("Choose habitat:\n");
      printf("1. aquatics\n");
      printf("2. savanna\n");
      printf("3. jungle\n");
      printf("4. river\n");
      printf("5. forest\n");
      printf("Enter your choice (1-5): ");
      scanf("%d", & habitat_choice);

      switch (habitat_choice) {
      case 1:
         strcpy(animals[id].habitat, habitat[0]);
         break;
      case 2:
         strcpy(animals[id].habitat, habitat[1]);
         break;
      case 3:
         strcpy(animals[id].habitat, habitat[2]);
         break;
      case 4:
         strcpy(animals[id].habitat, habitat[3]);
         break;
      case 5:
         strcpy(animals[id].habitat, habitat[4]);
         break;
      default:
         printf("Invalid input...........\n");
         continue;
      }

      id++;
      printf("The animal has been added successfully!\n");

      printf("Do you want to add another animal? (y/n): ");
      scanf(" %c", & continue_adding);
   } while (continue_adding == 'y' || continue_adding == 'Y');

}
///////////////////////////////////////////////////////////////
// Sort and display full list of animals
///////////////////////////////////////////////////////////////
void displayAllAnimals() {
   if (id == 0) {
      printf("There is nothing to display.\n");
      return;
   }

   for (int i = 0; i < id; i++) {
      printf("ID: %d | Name: %s | spice: %s | age: %d | Habitat: %s\n",
         animals[i].id, animals[i].name, animals[i].species, animals[i].age, animals[i].habitat);
   }
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
      int min_idx = i;
      for (int j = i + 1; j < id; j++) {
         if (strcmp(animals[j].name, animals[min_idx].name) < 0) {
            min_idx = j;
         }
      }
      if (min_idx != i) {
         Animal temp = animals[i];
         animals[i] = animals[min_idx];
         animals[min_idx] = temp;
      }
   }

   for (int i = 0; i < id; i++) {
      printf("ID: %d | Name: %s | spice: %s | age: %d | Habitat: %s\n",
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
      int min_idx = i;
      for (int j = i + 1; j < id; j++) {
         if (animals[j].age < animals[min_idx].age) {
            min_idx = j;
         }
      }
      if (min_idx != i) {
         Animal temp = animals[i];
         animals[i] = animals[min_idx];
         animals[min_idx] = temp;
      }
   }

   for (int i = 0; i < id; i++) {
      printf("ID: %d | Name: %s | spice: %s | age: %d | Habitat: %s\n",
         animals[i].id, animals[i].name, animals[i].species, animals[i].age, animals[i].habitat);
   }
}
///////////////////////////////////////////////////////////////
// display only animals from a specific habitat
///////////////////////////////////////////////////////////////
void displayAnimalsByHabitat(char habitat[]) {
   int found = 0;
   for (int i = 0; i < id; i++) {
      if (strcmp(animals[i].habitat, habitat) == 0) {
         printf("ID: %d | Name: %s | spice: %s | Age: %d | Habitat: %s\n",
            animals[i].id, animals[i].name, animals[i].species, animals[i].age, animals[i].habitat);
         found = 1;
      }
   }
   if (!found) {
      printf("No animals found in the habitat: %s\n", habitat);
   }
}
///////////////////////////////////////////////////////////////
// modifyAnimal by optiob of habitat or age.
///////////////////////////////////////////////////////////////
void modify_option_age_or_habitat(int index) {
   int choice;
   printf("What do you want to modify?\n");
   printf("1. Age\n");
   printf("2. Habitat\n");
   printf("Choose: ");
   scanf("%d", & choice);

   switch (choice) {
   case 1:
      printf("Enter new age: ");
      scanf("%d", & animals[index].age);
      printf("Age updated successfully!\n");
      break;
   case 2: {
      int habitat_choice;
      printf("Choose new habitat:\n");
      printf("1. aquatics\n");
      printf("2. savanna\n");
      printf("3. jungle\n");
      printf("4. river\n");
      printf("5. forest\n");
      printf("Enter your choice (1-5): ");
      scanf("%d", & habitat_choice);

      switch (habitat_choice) {
      case 1:
         strcpy(animals[index].habitat, habitat[0]);
         break;
      case 2:
         strcpy(animals[index].habitat, habitat[1]);
         break;
      case 3:
         strcpy(animals[index].habitat, habitat[2]);
         break;
      case 4:
         strcpy(animals[index].habitat, habitat[3]);
         break;
      case 5:
         strcpy(animals[index].habitat, habitat[4]);
         break;
      default:
         printf("Invalid input...........\n");
         return;
      }
      printf("Habitat updated successfully!\n");
      break;
   }
   default:
      printf("Invalid choice!\n");
   }
}
///////////////////////////////////////////////////////////////
// delete animal by id 
///////////////////////////////////////////////////////////////
void delete_animal_by_id(int index) {
    int found_index = -1;
   for (int i = 0; i < id; i++) {
      if (index == animals[i].id) {
         found_index = i;
         break;
      }
   }
   if (found_index == -1) {
         printf("Animal with ID %d not found!\n", index);
      } else {
         for (int j = found_index; j < id - 1; j++) {
            animals[j] = animals[j + 1];
            animals[j].id = j + 1;  
         }
         printf("Animal with ID %d has been deleted.\n", index);
         id--;
      }
}
///////////////////////////////////////////////////////////////
// search by id .
///////////////////////////////////////////////////////////////
void searchAnimalbyid() {
   int animal_id;
   int found_index = -1;

   printf("Enter the ID of the animal you want to search: ");
   scanf("%d", & animal_id);

   for (int i = 0; i < id; i++) {
      if (animals[i].id == animal_id) {
         found_index = i;
         break;
      }
   }

   if (found_index != -1) {
      printf("ID: %d | Name: %s | spice: %s | age: %d | Habitat: %s\n",
         animals[found_index].id, animals[found_index].name, animals[found_index].species, animals[found_index].age, animals[found_index].habitat);
   } else {
      printf("Animal with ID %d not found!\n", animal_id);
   }
}
///////////////////////////////////////////////////////////////
// search by name.
///////////////////////////////////////////////////////////////
void searchAnimalbyname() {
   char animal_name[50];
   int found_index = -1;

   printf("Enter the name of the animal you want to search: ");
   scanf("%s", &animal_name);

   for (int i = 0; i < id; i++) {
      if (animals[i].id == animal_name[50]) {
         found_index = i;
         break;
      }
   }

   if (found_index != -1) {
      printf("ID: %d | Name: %s | spice: %s | age: %d | Habitat: %s\n",
         animals[found_index].id, animals[found_index].name, animals[found_index].species, animals[found_index].age, animals[found_index].habitat);
   } else {
      printf("Animal with name %s not found!\n", animal_name[50]);
   }
}
int main() {
   int choice, choice_of_sorting;
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
      scanf("%d", & choice);

      switch (choice) {
      case 1:
         addAnimal();
         break;
      case 2:
         printf("Choose sorting method:\n");
         printf("1. full list\n");
         printf("2. By Name\n");
         printf("3. By Age\n");
         printf("4. By habitat\n");

         printf("Enter your choice: ");
         scanf("%d", & choice_of_sorting);
         if (choice_of_sorting == 1) {
            displayAllAnimals();
         } else if (choice_of_sorting == 2) {
            displayAnimalsByName();
         } else if (choice_of_sorting == 3) {
            displayAnimalsByAge();
         } else if (choice_of_sorting == 4) {
            int habitat_choice;
            printf("Choose habitat:\n");
            printf("1. aquatics\n");
            printf("2. savanna\n");
            printf("3. jungle\n");
            printf("4. river\n");
            printf("5. forest\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &habitat_choice);

            switch (habitat_choice) {
               case 1:
                  displayAnimalsByHabitat(habitat[0]);
                  break;
               case 2:
                  displayAnimalsByHabitat(habitat[1]);
                  break;
               case 3:
                  displayAnimalsByHabitat(habitat[2]);
                  break;
               case 4:
                  displayAnimalsByHabitat(habitat[3]);
                  break;
               case 5:
                  displayAnimalsByHabitat(habitat[4]);
                  break;
               default:
                  printf("Invalid habitat choice!\n");
            }
         } else {
            printf("Invalid choice!\n");
         }
         break;
      case 3: {
         int animal_id;
         int found_index = -1;

         printf("Enter the ID of the animal you want to modify: ");
         scanf("%d", & animal_id);

         for (int i = 0; i < id; i++) {
            if (animals[i].id == animal_id) {
               found_index = i;
               break;
            }
         }

         if (found_index != -1) {
            modify_option_age_or_habitat(found_index);
         } else {
            printf("Animal with ID %d not found!\n", animal_id);
         }
         break;
      }
      case 4:
        int animal_id;
        int found_index = -1;

        printf("Enter the ID of the animal you want to delete: ");
        scanf("%d", & animal_id);

         for (int i = 0; i < id; i++) {
            if (animals[i].id == animal_id) {
               found_index = i;
               break;
            }
         }

         delete_animal_by_id(animal_id);
         break;
      case 5:
         printf("Choose searching  method:\n");
         printf("1. By id\n");
         printf("2. By name\n");
         printf("3. By habitat\n");
         int search_choice;
         scanf("%d", &search_choice);
         switch (search_choice)
         {
         case 1 :
            searchAnimalbyid();
            break;
         case 2 :
            searchAnimalbyname();
            break;
         case 3 :
            {
               int habitat_choice;
               printf("Choose habitat:\n");
               printf("1. aquatics\n");
               printf("2. savanna\n");
               printf("3. jungle\n");
               printf("4. river\n");
               printf("5. forest\n");
               printf("Enter your choice (1-5): ");
               scanf("%d", &habitat_choice);

               switch (habitat_choice) {
                  case 1:
                     displayAnimalsByHabitat(habitat[0]);
                     break;
                  case 2:
                     displayAnimalsByHabitat(habitat[1]);
                     break;
                  case 3:
                     displayAnimalsByHabitat(habitat[2]);
                     break;
                  case 4:
                     displayAnimalsByHabitat(habitat[3]);
                     break;
                  case 5:
                     displayAnimalsByHabitat(habitat[4]);
                     break;
                  default:
                     printf("Invalid habitat choice!\n");
               }
            }
         
         default:
            break;
         }
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
   } while (choice != 0 || choice_of_sorting != 0 || choice < 0 || choice_of_sorting < 0 || choice > 6 || choice_of_sorting > 4);
   return 0;
}