#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10


struct HM_ENTRY
{
  char *key;
  char *value;
  struct HM_ENTRY *next;
};

struct HMap
{
  HM_ENTRY **entries;
};

HMap* initHashMap(void)
{
  HMap* htbl = malloc(sizeof(HMap) * 1); //assign memory pointer location for this datatype
  htbl->entries = malloc(sizeof(HM_ENTRY) * TABLE_SIZE);
  
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    char ind[20];
    
    sprintf(ind, "Slot: %d",i);
    Serial.println(ind);
    htbl->entries[i] = NULL;
  }
  return htbl;
}


unsigned int getHashIndex(const char *key)
{
  unsigned long int value = 0;
  unsigned int i = 0;
  unsigned int key_len = strlen(key);
  for (; i< key_len; ++i)
  {
    value = value * 37 + key[i];
  }

  value = value % TABLE_SIZE;
  return value;
}

HM_ENTRY* allocEntry(const char* key, const char* value)
{
  HM_ENTRY* entry = malloc(sizeof(*entry)+1);
  entry->key = malloc(strlen(key)+1);
  entry->value = malloc(strlen(value) + 1);
  strcpy(entry->key, key);
  strcpy(entry->value, value);
  entry->next = NULL;
    
  char klabels[50];
  strcpy(klabels,"Key: ");
  char vlabels[50];
  strcpy(vlabels,"Values: ");
  strcat(klabels,key);
  strcat(vlabels,value);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("Inserting");
  Serial.println(".............");
  Serial.println(klabels);
  Serial.println(vlabels);
  Serial.println(".............");
  char e_val[50] ;
  sprintf(e_val,"Entry Value: %s",entry->value);
  char k_val[50] ;
  sprintf(k_val,"Entry Key: %s",entry->key);
  Serial.println(e_val);
  Serial.println(k_val);
  Serial.println(".............");
  return entry;
}

void setEntry(HMap *htbl, const char *key, const char *value)
{
  unsigned int slot = getHashIndex(key);
  Serial.println("------------------------");
  Serial.println((int)&key);
  char smg[20];
  sprintf(smg,"Found Hash: %d",slot);
  Serial.println(smg);
  HM_ENTRY* entry = htbl->entries[slot];
  if (entry == NULL)
  {
    Serial.println("Called Add Method...");
    htbl->entries[slot] = allocEntry(key,value);
    return ;
  }
  HM_ENTRY *prev;

  while (entry != NULL)
  {
    if(strcmp(entry->key, key) == 0)
    {
    free(entry->value);
    entry->value = malloc(strlen(value) + 1);
    strcpy(entry->value, value);
    return ;
    }
    prev = entry;
    entry = prev->next;
  }
  prev->next = allocEntry(key,value);
}

char* HMGet(HMap *htbl, const char *key)
{
  unsigned int slot = getHashIndex(key);
  Serial.println("FOUND SLOT NUMBER IN GET");
  Serial.println(slot);
  HM_ENTRY* entry = htbl->entries[slot];
  if (entry == NULL)
  {
    Serial.println("GOT NULL ENTRY");
    return "NONE";
  }
  while (entry != NULL)
  {
    Serial.println("GOT ENTRY");
    Serial.println(entry->key);
    if (strcmp(entry->key, key) == 0)
    {
      return entry->value;
    }
    entry = entry->next;
  }
  return "NONE";
}

void HM_Dump(HMap *htbl)
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    HM_ENTRY* entry = htbl->entries[i];
    if (entry == NULL)
    {
      continue;
    }
    char slotmsg[100];
    sprintf(slotmsg, "Slot: %d",i);
    Serial.println(slotmsg);  

    for(;;)
    {

      char test[300];
      char keymsg[500];
      char valmsg[100];
      strcpy(keymsg,"Key: ");
      strcpy(valmsg, "Value: ");
      strcat(keymsg, entry->key);
      strcat(valmsg, entry->value);
      Serial.println(keymsg);
      Serial.println(valmsg);
      if (entry ->next == NULL)
      {
        break;
      }
      entry = entry->next;
    }
    Serial.println("Finished");
  } 
}

void main()
{
  HMap* hmp = initHashMap();
  setEntry(hmp, "Key1", "Value1")
}
