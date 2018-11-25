#include <bitset>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

#include "astree.h"
#include "symtable.h"

int blocknr = 0;
int next_block = 1;

symbol_table* types = new symbol_table;
symbol_table* variables = new symbol_table;
symbol_table globaldecs;

enum class attr: unsigned {
       VOID, INT, NULLX, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE,
       FIELD, TYPEID, PARAM, LOCAL, LVAL, CONST, VREG, VADDR, BITSET_SIZE,
};

const string attrString(astree* node) {
    string attrString = "";
    if(node->attributes[unsigned(attr::VOID)]) {
       attrString += "void ";
    }
    if(node->attributes[unsigned(attr::INT)]) {
       attrString += "int ";
    }
    if(node->attributes[unsigned(attr::NULLX)]) {
       attrString += "null ";
    }
    if(node->attributes[unsigned(attr::STRING)]) {
       attrString += "string ";
    }
    if(node->attributes[unsigned(attr::STRUCT)]) {
       attrString += "struct ";
       if(node->strucname != nullptr) {attrString += node->strucname -> c_str();}
       attrString += " ";
    }
    if(node->attributes[unsigned(attr::ARRAY)]) {
       attrString += "array ";
    }
    if(node->attributes[unsigned(attr::FUNCTION)]) {
       attrString += "function ";
    }
    if(node->attributes[unsigned(attr::VARIABLE)]) {
       attrString += "variable ";
    }
    if(node->attributes[unsigned(attr::FIELD)]) {
       attrString += "field ";
    }
    if(node->attributes[unsigned(attr::TYPEID)]) {
       attrString += "typeid ";
    }
    if(node->attributes[unsigned(attr::LVAL)]) {
       attrString += "lval ";
    }
    if(node->attributes[unsigned(attr::PARAM)]) {
      attrString += "param ";
    }
    if(node->attributes[unsigned(attr::LOCAL)]) {
      attrString += "local ";
    }
    if(node->attributes[unsigned(attr::CONST)]) {
       attrString += "const ";
    }
    if(node->attributes[unsigned(attr::VREG)]) {
       attrString += "vreg ";
    }
    if(node->attributes[unsigned(attr::VADDR)]) {
       attrString += "vaddr ";
    }
    return attrString;
}

const string attrStringSym(symbol* node) {
    string attrString = "";
    if(node->attributes[unsigned(attr::VOID)]) {
       attrString += "void ";
    }
    if(node->attributes[unsigned(attr::INT)]) {
       attrString += "int ";
    }
    if(node->attributes[unsigned(attr::NULLX)]) {
       attrString += "null ";
    }
    if(node->attributes[unsigned(attr::STRING)]) {
       attrString += "string ";
    }
    if(node->attributes[unsigned(attr::STRUCT)]) {
       attrString += "struct ";
       attrString += node->strucname -> c_str();
       attrString += " ";
    }
    if(node->attributes[unsigned(attr::ARRAY)]) {
       attrString += "array ";
    }
    if(node->attributes[unsigned(attr::FUNCTION)]) {
       attrString += "function ";
    }
    if(node->attributes[unsigned(attr::VARIABLE)]) {                                                                                                                                         
       attrString += "variable ";                                                                                                                                                            
    }
    if(node->attributes[unsigned(attr::FIELD)]) {                                                                                                                                            
       attrString += "field ";                                                                                                                                                               
    }
    if(node->attributes[unsigned(attr::TYPEID)]) {                                                                                                                                           
       attrString += "typeid ";                                                                                                                                                              
    }
    if(node->attributes[unsigned(attr::LVAL)]) {
       attrString += "lval ";                                                                                                                                                                
    }
    if(node->attributes[unsigned(attr::PARAM)]) {
      attrString += "param ";
    }
    if(node->attributes[unsigned(attr::LOCAL)]) {
      attrString += "local ";
    }
    if(node->attributes[unsigned(attr::CONST)]) {                                                                                                                                            
       attrString += "const ";                                                                                                                                                               
    }
    if(node->attributes[unsigned(attr::VREG)]) {                                                                                                                                             
       attrString += "vreg ";                                                                                                                                                                
    }
    if(node->attributes[unsigned(attr::VADDR)]) {                                                                                                                                            
       attrString += "vaddr ";                                                                                                                                                               
    }
    attrString = attrString.substr(0, attrString.size()-1);
    return attrString;
}

symbol* newSym(astree* node) {
   symbol* sym = new symbol();
   sym -> attributes = node -> attributes;
   sym -> sequence = 0;
   sym -> fields = nullptr;
   sym -> lloc = node -> lloc;
   sym -> block_nr = node -> block_nr;
   //sym -> parameters = nullptr;
   sym -> strucname = node -> strucname;
   sym -> funcname = nullptr;
   return sym;    
}

// Print the symbols for .sym
void printTable(symbol_table* table) { 
    for ( auto it = table -> cbegin(); it != table -> cend(); it++ ) {
        printf("%s (%lu.%lu.%lu) {%lu} %s\n", it->first->c_str(), it->second->lloc.filenr, 
        it->second->lloc.linenr, it->second->lloc.offset, it->second->block_nr, 
        attrStringSym(it->second).c_str());
        if (it->second->fields != nullptr) {
           for (auto field = it->second->fields->cbegin(); field != it->second->fields->cend(); field++) {
               printf("    %s (%lu.%lu.%lu) %s %lu\n", field->first->c_str(), field->second->lloc.filenr, 
               field->second->lloc.linenr, field->second->lloc.offset, 
               attrStringSym(field->second).c_str(), field->second->sequence);
           }
        } 
    }                                                                                                                                                                                        
}

void addStruct(symbol* currStruc, const string* strucID, const string* id, astree* node) {
    symbol* temp = types->find(strucID)->second;
    symbol* val = currStruc->fields->find(id)->second;
    val->attributes[unsigned(attr::STRUCT)] = 1;
    val->strucname = temp->strucname;
    node->attributes = val->attributes;
    node->strucname = temp->strucname;
}

symbol* findTypeid(const string* strucID) {
    symbol* temp = types->find(strucID)->second;
    return temp;
}

symbol* findVariable(const string* varID) {
    symbol* temp = variables->find(varID)->second;
    return temp;
}

//symbol* findStruc(const string varID) { 
//      symbol* temp = 
bool typecheckUnop(astree* node) {
     if ( node->children[0]->attributes[unsigned(attr::INT)] != 1 ) {
        return false;
     }
     return true;
}

bool typecheckMath(astree* node) {
        
        if ( node->children[0]->attributes[unsigned(attr::VARIABLE)] == 1 && node->children[1]->attributes[unsigned(attr::VARIABLE)] == 0 )
        {
            symbol* temp = findVariable(node->children[0]->lexinfo);
            if ( temp -> attributes[unsigned(attr::INT)] == 1 ) 
            {
                return true;
            }
            return false;
        }
        // Right operand is a variable and left one isn't
        if ( node->children[0]->attributes[unsigned(attr::VARIABLE)] == 0 && node->children[1]->attributes[unsigned(attr::VARIABLE)] == 1 )
        {
            symbol* temp = findVariable(node->children[1]->lexinfo);
            if ( temp -> attributes[unsigned(attr::INT)] == 1 )
            {
                return true;
            }
            return false;
        }
        //both variables
        if ( node->children[0]->attributes[unsigned(attr::VARIABLE)] == 1 && node->children[1]->attributes[unsigned(attr::VARIABLE)] == 1 )
        {
            symbol* temp = findVariable(node->children[0]->lexinfo);
            symbol* temp2 = findVariable(node->children[1]->lexinfo);
            if ( temp -> attributes[unsigned(attr::INT)] == 1 && temp2 -> attributes[unsigned(attr::INT)] == 1 )
            {
                return true;
            }
            return false;
        }
	// Just integer
        if ( node->children[0]->attributes[unsigned(attr::INT)] != 1 || node->children[1]->attributes[unsigned(attr::INT)] != 1 ) 
        {
		return false;
	}
        return true;
}

bool typecheckExpr(astree* node) { 
     //printf("%d", unsigned(attr::FUNCTION));
     if ( node->children[0]->children[0]->attributes[unsigned(attr::VARIABLE)] == 1 && node->children[0]->children[1]->attributes[unsigned(attr::VARIABLE)] == 0 )
     {
         symbol* temp = findVariable(node->children[0]->children[0]->lexinfo);
         for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {  
             if ( temp -> attributes[i] != node->children[0]->children[1]->attributes[i] ) {
                 return false;
             }
         }
         return true;
     }
     else if ( node->children[0]->children[0]->attributes[unsigned(attr::VARIABLE)] == 0 && node->children[0]->children[1]->attributes[unsigned(attr::VARIABLE)] == 1 )
     {
        symbol* temp = findVariable(node->children[0]->children[1]->lexinfo);
        for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
        if ( temp -> attributes[i] != node->children[0]->children[0]->attributes[i] ) {
             return false;
           }
        }
        return true;
     }
     else if ( node->children[0]->children[0]->attributes[unsigned(attr::VARIABLE)] == 1 && node->children[0]->children[1]->attributes[unsigned(attr::VARIABLE)] == 1 )
     {
        symbol* temp = findVariable(node->children[0]->children[0]->lexinfo);
        symbol* temp2 = findVariable(node->children[0]->children[1]->lexinfo);
        for (size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {  
        if ( temp -> attributes[i] !=  temp2 -> attributes[i] ) {
           return false;
           }  
        }
        return true;
     }
     else 
     {
         for (size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) { 
         if ( node->children[0]->children[0]->attributes[i] != node->children[0]->children[1]->attributes[i] ) { 
             return false;
         }
      } 
      return true;
     }
}

void checkVarDecl(astree* block)  {
      if ( block->children[1]->attributes[unsigned(attr::NULLX)] == 1)
      {
          return;
      }
      for (size_t i = 0; i < unsigned(attr::FUNCTION); ++i) {
           if (block->children[0]->children[0]->attributes[i] != block->children[1]->attributes[i] ) {
               printf("Not compatible variable declaration at : (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
               return;
            }
      }
      return;
}

void checkArrow(astree* block) {
    if( block->children[0]->symbol == TOK_ARROW ) {
       // handle double -> here
       return;
    }
    symbol* temp = findVariable(block->children[0]->lexinfo);
    const string* lookupName = temp->strucname;
    //printf("LOOKUP NAME: %s\n", lookupName->c_str());
    if( findTypeid(lookupName) == NULL ) {
       fprintf(stderr, "Nonexistent structure referenced");
       return;
    }
    symbol* tempStruct = findTypeid(lookupName);
    symbol* fieldSym = tempStruct->fields->find(block->children[1]->lexinfo)->second;
    //printf("%s\n", attrStringSym(fieldSym).c_str());
    for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
       if ( fieldSym->attributes[i] == 1 ) {
          block->attributes[i] = 1;
       }
    }
    block->children[0]->attributes[unsigned(attr::STRUCT)] = 1;
    block->children[0]->strucname = lookupName;
    block->attributes[unsigned(attr::STRUCT)] = 0;
    block->attributes[unsigned(attr::VADDR)] = 1;                                                                                               
    block->attributes[unsigned(attr::LVAL)]  = 1;
    return;      
}
/*
void checkArrow(astree* block) {
    if ( findTypeid(block->children[0]->lexinfo) == NULL ) {
         printf("Non existent structure");
         return;
      }
      symbol* temp = findTypeid(block->children[0]->lexinfo);
      if ( temp->attributes[unsigned(attr::STRUCT)] == 1 ){
        symbol* lookup = temp->fields->find(block->children[1]->lexinfo)->second;
        for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
           if ( lookup->attributes[i] == 1 ) {
                    block->attributes[i] = 1;
           }
        }
        
        block->attributes[unsigned(attr::VADDR)] = 1;
        block->attributes[unsigned(attr::LVAL)]  = 1;
        return;
        }
        printf("Improper use of field selector at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
        return;
}
*/
void checkIndex(astree* block) {
                   symbol* temp = findVariable(block->children[0]->lexinfo);
                   if ( temp->attributes[unsigned(attr::STRING)] == 1 ) {

                       block->attributes[unsigned(attr::INT)] = 1;
                       block->attributes[unsigned(attr::VADDR)] = 1;
                       block->attributes[unsigned(attr::LVAL)] = 1;
                       return;
                   }
                   for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++ i ) {
                       if ( temp->attributes[i] == 1 ) {
                           block->attributes[i] = 1;
                       }
                   }
                   block->attributes[unsigned(attr::VADDR)] = 1;
                   block->attributes[unsigned(attr::LVAL)] = 1;
                   return;
}


void checkIndexArrow(astree* block) {
      symbol* temp = findTypeid(block->children[0]->children[0]->lexinfo);
      if ( temp->attributes[unsigned(attr::STRUCT)] == 1 ){
        symbol* lookup = temp->fields->find(block->children[0]->children[1]->lexinfo)->second;
        if ( lookup ->attributes[unsigned(attr::STRING)] == 1 ) { 
              block->attributes[unsigned(attr::INT)] = 1;
                       block->attributes[unsigned(attr::VADDR)] = 1;
                       block->attributes[unsigned(attr::LVAL)] = 1;
                       return;
        }
        for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
           if ( lookup->attributes[i] == 1 ) {
                    block->attributes[i] = 1;
           }
        }
        block->attributes[unsigned(attr::VADDR)] = 1;
        return;
        }
        printf("Improper use of field selector at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
        return;
}




void handleBlock(astree* blockNode, astree* returnType) {
    for (astree* block : blockNode->children) {
        switch (block -> symbol) {
            case TOK_VARDECL : {
                checkVarDecl(block); 
                int blockCounter = 0;
                if ( block->children[0]->symbol == TOK_ARRAY ) {
                    if ( block->children[0]->children[0]->symbol == TOK_TYPEID ) {
                        symbol* struc = findTypeid(block->children[0]->children[0]->lexinfo);
                        block->children[0]->children[0]->children[0]->attributes[unsigned(attr::STRUCT)] = 1;
                        block->children[0]->children[0]->children[0]->strucname = struc->strucname;
                    }
                    block->children[0]->children[0]->children[0]->boolLoc = 1;
                    block->children[0]->children[0]->children[0]->decLloc = block->children[0]->children[0]->lloc;
                    block->children[0]->children[0]->children[0]->attributes[unsigned(attr::LOCAL)] = 1;
                    symbol* dec = newSym(block->children[0]->children[0]->children[0]);
                    dec -> sequence = blockCounter;
                    dec -> block_nr = blocknr;
                    blockCounter++;
                    variables->insert(std::make_pair(block->children[0]->children[0]->children[0]->lexinfo, dec));
                    printf("    %s (%lu.%lu.%lu) {%lu} %s %lu\n", block->children[0]->children[0]->children[0]->lexinfo->c_str(), dec->lloc.filenr,
                    dec->lloc.linenr, dec->lloc.offset, dec->block_nr,
                    attrStringSym(dec).c_str(), dec->sequence);
                        
                }
                else {
                    if ( block->children[0]->symbol == TOK_TYPEID ) {
                        symbol* struc = findTypeid(block->children[0]->lexinfo);
                        block->children[0]->children[0]->attributes[unsigned(attr::STRUCT)] = 1;
                        block->children[0]->children[0]->strucname = struc->strucname;
                    }
                    block->children[0]->children[0]->boolLoc = 1;
                    block->children[0]->children[0]->decLloc = block->children[0]->lloc;
                    block->children[0]->children[0]->attributes[unsigned(attr::LOCAL)] = 1;
                    symbol* dec = newSym(block->children[0]->children[0]);
                    dec -> sequence = blockCounter;
                    dec -> block_nr = blocknr;
                    blockCounter++;
                    variables->insert(std::make_pair(block->children[0]->children[0]->lexinfo, dec)); 
                    printf("    %s (%lu.%lu.%lu) {%lu} %s %lu\n", block->children[0]->children[0]->lexinfo->c_str(), dec->lloc.filenr,
                    dec->lloc.linenr, dec->lloc.offset, dec->block_nr,
                    attrStringSym(dec).c_str(), dec->sequence);
                }
                if ( block->children[1]->symbol == TOK_ARROW ) {
                    checkArrow(block->children[1]);
                }
                break;
            }
            case TOK_IF :
                //printf("%s", block->children[0]->lexinfo->c_str());
                if ( typecheckExpr(block) )
                {
                    handleBlock(block, returnType);
                    break;
                }
                printf("Comparing two different types at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                break;
            case TOK_WHILE : {
                break; }
            case TOK_CALL :
                break;
            case TOK_POS :
            case TOK_NEG : {
              //printf("%s", block->children[0]->lexinfo->c_str());
              if ( typecheckUnop(block) ) 
              {
                  //printf("%s", block->children[0]->lexinfo->c_str());
                  handleBlock(block, returnType);
                  break;
              } 
              printf("Non Integer on unop expression at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
              break;       
           }
           case TOK_RETURN : { 
                //printf("%s", block->children[0]->lexinfo->c_str());
                
                if ( block->children.size() > 0 && block->children[0]->symbol == TOK_ARROW ) {
                     printf("hi again");
                     checkArrow(block->children[0]);
                     handleBlock(block, returnType);
                     break;
                }/* 
                if ( block->children[0]->children[0]->symbol == TOK_ARROW ) { 
                     printf("hi");
                     //checkArrow(block->children[0]->children[0]);
                     //handleBlock(block, returnType);
                     break;
                }*/
                

                if ( returnType->attributes[unsigned(attr::VOID)] == 1 )
                {
                    printf("Return type in void function at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                    handleBlock(block, returnType);
                    break;
                }
 
                if ( block->children[0]->attributes[unsigned(attr::VARIABLE)] == 1 )
               {
                  symbol* temp = findVariable(block->children[0]->lexinfo);
                  for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
                      if (returnType->attributes[i] != temp->attributes[i] ) {

                             printf("Not compatible return types at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                             handleBlock(block, returnType);
                             break;
                          }
                  }
                  handleBlock(block, returnType);
                  break;
                }

                for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) { 
                    if (returnType->attributes[i] != block->children[0]->attributes[i] ) 
                    {
                    	printf("Not compatible return types at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                        handleBlock(block, returnType);
                        break;
                    }
                }
                handleBlock(block, returnType);
                break;
            }
            case '=' : {
                if ( block->children[0]->symbol == TOK_INDEX ) {
                   if ( block->children[0]->children[0]->symbol == TOK_ARROW) {
                        //checkIndex(block->children[0]);
                        checkIndexArrow(block->children[0]);
                        checkArrow(block->children[0]->children[0]);
                        checkArrow(block->children[0]->children[1]);
                        for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
                           if ( block->children[0]->children[0]->attributes[i] == 1 ) {
                              block->attributes[i] = 1;
                           }
                        } 
                        //handleBlock(block, returnType);
                        break;
                    } 
                    else {
                    checkIndex(block->children[0]);
                    handleBlock(block, returnType);
                    break;
                    }
                }
                if ( block->children[0]->symbol == TOK_ARROW ) { 
                     checkArrow(block->children[0]);
                     for ( size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
                           if ( block->children[0]->attributes[i] == 1 ) {
                              block->attributes[i] = 1;
                           }
                        }
                     handleBlock(block, returnType);
                     break;
                }
                
		if ( block->children[1]->attributes[unsigned(attr::NULLX)] == 1 ) 
                {
                    block->attributes[unsigned(attr::NULLX)] = 1;
                    handleBlock(block, returnType);
                    break;
                }
                
                symbol* temp = findVariable(block->children[0]->lexinfo);
                for (size_t i = 0; i < unsigned(attr::FUNCTION); ++i ) {
                   if (temp->attributes[i] != block->children[1]->attributes[i] ) {
                      printf("Not compatible assigment to variable at: (%lu.%lu.%lu) \n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                      handleBlock(block, returnType);
                      break;
                   }
                   if ( temp->attributes[i] == 1 && block->children[1]->attributes[i] == 1 ) 
                   {
                       block->attributes[i] = 1;
                   }
                } 
                
                handleBlock(block, returnType);                
                break;
             }
             case TOK_ARROW : {
                  checkArrow(block);
                  handleBlock(block, returnType);
                  break;
              } 
              case TOK_INDEX : {
                   checkIndex(block);
                   handleBlock(block, returnType);
                   break;
             }
              case TOK_IDENT : { 
                  symbol* temp = findVariable(block->children[0]->lexinfo);
                  break;
              }
              case TOK_NEW : 
                   break;
        }
         
    }
}


void setFuncBlockNums(astree* root) {
    for (astree* node : root->children) {
        node->block_nr = blocknr;
        setFuncBlockNums(node);
    }
}


void traversal(astree* root) {
  for (astree* childNode: root -> children) {
      //printf("Token: %s\n", parser::get_tname(childNode -> symbol));
      switch(childNode -> symbol) {
         case TOK_STRUCT : {
            childNode -> strucname = childNode -> children[0] -> lexinfo;
            auto* sym = newSym(childNode);
            sym -> lloc = childNode -> children[0] -> lloc;
            sym -> attributes = childNode -> children[0] -> attributes;
            int counter = 0;
            sym -> fields = new symbol_table();
            vector <astree*> v;
            types -> insert(std::make_pair(childNode -> children[0] -> lexinfo, sym));
            printf("%s (%lu.%lu.%lu) {%lu} %s\n", sym->strucname->c_str(), sym->lloc.filenr,
            sym->lloc.linenr, sym->lloc.offset, sym->block_nr,
            attrStringSym(sym).c_str());
            for (astree* fieldNode: childNode -> children) {
               if (fieldNode -> children.size() >= 1 && fieldNode -> children[0] -> symbol == TOK_FIELD) {
                 const string* id = fieldNode->children[0]->lexinfo;
                 auto* fieldSym = newSym(fieldNode->children[0]);
                 fieldSym->sequence = counter;
                 sym->fields->insert(std::make_pair(fieldNode->children[0]->lexinfo, fieldSym));
                 if(fieldNode->symbol == TOK_TYPEID) {
                    const string* strucID = fieldNode->lexinfo;
                    const string* ident = fieldNode->children[0]->lexinfo;
                    addStruct(sym, strucID, ident, fieldNode->children[0]);
                 }
                 printf("    %s (%lu.%lu.%lu) %s %lu\n", id->c_str(), fieldSym->lloc.filenr,
                 fieldSym->lloc.linenr, fieldSym->lloc.offset,
                 attrStringSym(fieldSym).c_str(), fieldSym->sequence);
                 counter++;
               }
              else if (fieldNode -> symbol == TOK_ARRAY) {
                 auto* fieldSym = newSym(fieldNode->children[0]->children[0]);
                 fieldSym->sequence = counter;
                 sym->fields->insert(std::make_pair(fieldNode->children[0]->children[0]->lexinfo, fieldSym));
                 if(fieldNode->children[0]->symbol == TOK_TYPEID) {
                    const string* strucID = fieldNode->children[0]->lexinfo;
                    const string* id = fieldNode->children[0]->children[0]->lexinfo;
                    addStruct(sym, strucID, id, fieldNode->children[0]->children[0]);
                 }
                 printf("    %s (%lu.%lu.%lu) %s %lu\n", fieldNode->children[0]->children[0]->lexinfo->c_str(), fieldSym->lloc.filenr,
                 fieldSym->lloc.linenr, fieldSym->lloc.offset,
                 attrStringSym(fieldSym).c_str(), fieldSym->sequence);
                 counter++;
              }
              
            }
            printf("\n");
            break;
         }
         case TOK_FUNCTION : {
            symbol* sym = newSym(childNode);
            sym -> attributes = childNode->children[0]->children[0]->attributes;
            sym -> funcname = childNode->children[0]->children[0]->lexinfo;
            sym -> lloc = childNode->children[0]->children[0]->lloc;
            sym -> block_nr = blocknr;
            blocknr++;
            
            setFuncBlockNums(childNode);
            childNode->block_nr = blocknr-1;
            childNode->children[0]->block_nr = blocknr-1;
            childNode->children[0]->children[0]->block_nr = blocknr-1;
            if(childNode->children[0]->symbol == TOK_TYPEID) {
              symbol* temp = findTypeid(childNode->children[0]->lexinfo);
              sym->attributes[unsigned(attr::STRUCT)] = 1;
              sym->strucname = temp->strucname;
              childNode->children[0]->children[0]->strucname = temp->strucname;
            }
            sym->attributes[unsigned(attr::VARIABLE)] = 0;
            childNode->children[0]->children[0]->attributes = sym->attributes;
            variables->insert(std::make_pair(sym->funcname, sym));
            printf("%s (%lu.%lu.%lu) {%lu} %s\n", sym->funcname->c_str(), sym->lloc.filenr,
            sym->lloc.linenr, sym->lloc.offset, sym->block_nr,
            attrStringSym(sym).c_str());
           
            astree* params = childNode->children[1];
            int paraCounter = 0;
            
            for(astree* parameter : params->children) {
               astree* ident = parameter->children[0];
               if(parameter->symbol == TOK_ARRAY) {
                 ident = ident->children[0];
               }
               symbol* currParam;
               if(parameter->symbol != TOK_ARRAY) {
                  currParam = newSym(parameter->children[0]);
               }
               else {
                  currParam = newSym(parameter->children[0]->children[0]);
               }
               currParam->sequence = paraCounter;
               currParam->block_nr = blocknr;
               paraCounter++;
               if(parameter->symbol != TOK_ARRAY) {
                  if(parameter->symbol == TOK_TYPEID) {
                     symbol* struc = findTypeid(parameter->lexinfo);
                     parameter->children[0]->attributes[unsigned(attr::STRUCT)] = 1;
                     parameter->children[0]->strucname = struc->strucname; 
                     currParam->attributes = parameter->children[0]->attributes;
                     currParam->strucname = struc->strucname; 
                  }
                  currParam->param_name = parameter->children[0]->lexinfo;
                  sym->parameters.push_back(currParam);
                  parameter->children[0]->boolLoc = 1;
                  parameter->children[0]->decLloc = parameter->lloc;
               }
               else {
                  if(parameter->children[0]->symbol == TOK_TYPEID) {
                     symbol* struc = findTypeid(parameter->children[0]->lexinfo);
                     parameter->children[0]->children[0]->attributes[unsigned(attr::STRUCT)] = 1;
                     parameter->children[0]->children[0]->strucname = struc->strucname;
                     currParam->attributes = parameter->children[0]->children[0]->attributes;
                     currParam->strucname = struc->strucname;
                  }
                  currParam->param_name = parameter->children[0]->children[0]->lexinfo;
                  sym->parameters.push_back(currParam);
                  parameter->children[0]->children[0]->boolLoc = 1;
                  parameter->children[0]->children[0]->decLloc = parameter->children[0]->lloc; 
               }
               printf("    %s (%lu.%lu.%lu) {%lu} %s %lu\n", currParam->param_name->c_str(), currParam->lloc.filenr,
               currParam->lloc.linenr, currParam->lloc.offset, currParam->block_nr,
               attrStringSym(currParam).c_str(), currParam->sequence);
               variables->insert(std::make_pair(currParam->param_name, currParam));
            }
            
            astree* block = childNode -> children[2];
            astree* returnType = childNode->children[0]->children[0];
            handleBlock(block, returnType);
            printf("\n");
            break;
         }  

         case TOK_TYPEID :
            //childNode -> attributes[unsigned(attr::TYPEID)] = 1;
            break;
         case '+':
         case '-': 
         case '*':
         case '%':
         case '/': {
	     if (typecheckMath(childNode) )
             {
		break;
             }
             printf("Non Int operands used at: (%lu.%lu.%lu) \n", childNode->lloc.filenr, childNode->lloc.linenr, childNode->lloc.offset);
             break;
         }
         default :
            break;
      }
      traversal(childNode);
  }
}



void updateAttr(astree* root) {
   for (astree* childNode: root -> children) {
      switch(childNode -> symbol) {
         case TOK_ROOT : 
            break;
         case TOK_STRUCT : {
            childNode -> children[0] -> attributes[unsigned(attr::STRUCT)] = 1;
            childNode -> children[0] -> strucname = childNode -> children[0] -> lexinfo;
            break;
         }
         case TOK_TYPEID : {
            if(childNode -> attributes[unsigned(attr::STRUCT)] == 0) { 
               childNode -> attributes[unsigned(attr::TYPEID)] = 1;
            }
            break;
         }
         case TOK_FIELD : {
            childNode -> attributes[unsigned(attr::FIELD)] = 1;
            break;
         }
         case TOK_FUNCTION : {
              childNode -> children[0] -> children[0] -> attributes[unsigned(attr::FUNCTION)] = 1;
              break;
         }
         case TOK_VARDECL :
              childNode -> children[0] -> children[0] -> attributes[unsigned(attr::VARIABLE)] = 1;
              childNode -> children[0] -> children[0] -> attributes[unsigned(attr::LVAL)] = 1; 
	      break;
         case TOK_VOID :
            childNode -> children[0] -> attributes[unsigned(attr::VOID)] = 1; 
            break;
         case TOK_INT :
            if(childNode->children.size() > 0) { 
               childNode -> children[0] -> attributes[unsigned(attr::INT)] = 1;
            }
            break;
         case TOK_NULL : 
            childNode -> attributes[unsigned(attr::NULLX)] = 1;
            childNode -> attributes[unsigned(attr::CONST)] = 1;
            break;
         case TOK_STRING : 
            if(childNode->children.size() > 0) { childNode -> children[0] -> attributes[unsigned(attr::STRING)] = 1; }
            break;
         case TOK_PARAM : {
            for (astree* parameters : childNode -> children) {
                if(parameters->symbol != TOK_ARRAY) {
                   parameters->children[0]->attributes[unsigned(attr::LVAL)] = 1;
                   parameters->children[0]->attributes[unsigned(attr::PARAM)] = 1;
                }
                else {
                   parameters->children[0]->children[0]->attributes[unsigned(attr::LVAL)] = 1;
                   parameters->children[0]->children[0]->attributes[unsigned(attr::PARAM)] = 1;
                }
            }
            break;
         }
         case TOK_DECLID : {
            childNode -> attributes[unsigned(attr::VARIABLE)] = 1;
            break;   
         }
         case TOK_IDENT : 
            break;
         case TOK_ARRAY : 
            childNode -> children[0] -> children[0] -> attributes[unsigned(attr::ARRAY)] = 1;
            break;
         case TOK_INTCON:
            childNode -> attributes[unsigned(attr::INT)] = 1;
            childNode -> attributes[unsigned(attr::CONST)] = 1;
            break;
         case TOK_STRINGCON :
            childNode -> attributes[unsigned(attr::STRING)] = 1;
            childNode -> attributes[unsigned(attr::CONST)] = 1;
            break;
         case TOK_BLOCK :
            break;
         case '=' :
             childNode -> attributes[unsigned(attr::VREG)] = 1;
             break; 
         case '+' :
         case '-' : {
             childNode -> attributes[unsigned(attr::INT)] = 1;
             childNode -> attributes[unsigned(attr::VREG)] = 1;
             break; 
         }
         case '/' : 
         case '%' : 
         case '*' : {
            childNode -> attributes[unsigned(attr::INT)] = 1;
            childNode -> attributes[unsigned(attr::VREG)] = 1;
	    break;
         }
         case TOK_POS: 
         case TOK_NEG: { 
              childNode->attributes[unsigned(attr::INT)] = 1;
              childNode->attributes[unsigned(attr::VREG)]=1;
              break;
         }
         case TOK_EQ: 
         case TOK_NE: 
         case TOK_LT: 
         case TOK_LE: 
         case TOK_GT: 
         case TOK_GE: {
	      childNode -> attributes[unsigned(attr::INT)] = 1;
              childNode -> attributes[unsigned(attr::VREG)] = 1;
              break;
         }
         case TOK_ARROW : 
              childNode -> children[0] -> attributes[unsigned(attr::LVAL)] = 1;
              break;
         case TOK_NEW : 
              break;
         case TOK_NEWARRAY : 
              childNode -> attributes[unsigned(attr::VREG)] = 1;
              childNode -> attributes[unsigned(attr::ARRAY)] = 1;
              break;
         default : 
           printf("Press F to pay respect: %s\n", parser::get_tname(childNode->symbol));
      }
      updateAttr(childNode);
   }   

}
