#include <stdio.h>
#include <assert.h>
#include "../include/csv.h"
#include "../include/api.h"

#include <string.h>


#define FILE_READ_BUFFER_SIZE 2048

// Get the API version information
const char* api_version() {
    return "UOC PP 20241";
}

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset) {
    tApiError error;
    FILE *fin;    
    char buffer[FILE_READ_BUFFER_SIZE];
    tCSVEntry entry;
    
    // Check input data
    assert( data != NULL );
    assert(filename != NULL);
    
    // Reset current data    
    if (reset) {
        // Remove previous information
        error = api_freeData(data);
        if (error != E_SUCCESS) {
            return error;
        }
        
        // Initialize the data
        error = api_initData(data);
        if (error != E_SUCCESS) {
            return error;
        }
    }

    // Open the input file
    fin = fopen(filename, "r");
    if (fin == NULL) {
        return E_FILE_NOT_FOUND;
    }
    
    // Read file line by line
    while (fgets(buffer, FILE_READ_BUFFER_SIZE, fin)) {
        // Remove new line character     
        buffer[strcspn(buffer, "\n\r")] = '\0';
        
        csv_initEntry(&entry);
        csv_parseEntry(&entry, buffer, NULL);
        // Add this new entry to the api Data
        error = api_addDataEntry(data, entry);
        if (error != E_SUCCESS) {
            return error;
        }
        csv_freeEntry(&entry);
    }
    
    fclose(fin);
    
    return E_SUCCESS;
}

// Initialize the data structure
tApiError api_initData(tApiData* data) {            
    //////////////////////////////////
    // Ex PR1 2b
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a tenant into the data if it does not exist
tApiError api_addTenant(tApiData* data, tCSVEntry entry) {
    //////////////////////////////////
    // Ex PR1 2c
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a landlord if it does not exist
tApiError api_addLandlord(tApiData* data, tCSVEntry entry) {
    //////////////////////////////////
    // Ex PR1 2d
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a property into the properties of an specific landlord
tApiError api_addProperty(tApiData* data, tCSVEntry entry) {
    //////////////////////////////////
    // Ex PR1 2e
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a rental income into a list if the landlord already exists
tApiError api_addRentalIncome(tApiData* data, tCSVEntry entry) {
    //////////////////////////////////
    // Ex PR1 2f
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Find a rental income by year and landlord document id
tRentalIncome* rentalIncomes_find(tRentalIncomeList list, int year, const char* document_id) {
    //////////////////////////////////
    // Ex PR1 2g
    /////////////////////////////////
    
    /////////////////////////////////
    return NULL;
}

// Get the number of tenants registered on the application
int api_tenantCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2h
    /////////////////////////////////
    
    /////////////////////////////////
    return -1;
}


// Get the number of landlords registered on the application
int api_landlordsCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2h
    /////////////////////////////////
    
    /////////////////////////////////
    return -1;
}

// Get the number of properties in all landlords registered on the application
int api_propertiesCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2h
    /////////////////////////////////
	
    /////////////////////////////////
    return -1;
}

// Get the number of rental incomes registered
int api_rentalIncomesCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2h
    /////////////////////////////////
	
    /////////////////////////////////
    return -1;
}


// Free all used memory
tApiError api_freeData(tApiData* data) {
    //////////////////////////////////
    // Ex PR1 2i
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}


// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry) { 
    //////////////////////////////////
    // Ex PR1 2j
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Get landlord data
tApiError api_getLandlord(tApiData data, const char *id, tCSVEntry *entry) {
    //////////////////////////////////
    // Ex PR1 3a
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED; 
}

// Get the rental income by year of a landlord
tApiError api_getRentalIncome(tApiData data, int year, const char* id, tCSVEntry *entry) {
    //////////////////////////////////
    // Ex PR1 3b
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED; 
}

// Get registered properties
tApiError api_getProperties(tApiData data, tCSVData *properties) {
    //////////////////////////////////
    // Ex PR1 3c
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Get registered rental incomes
tApiError api_getRentalIncomes(tApiData data, tCSVData *rentalIncomes) {
    //////////////////////////////////
    // Ex PR1 3d
    /////////////////////////////////
    
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}
