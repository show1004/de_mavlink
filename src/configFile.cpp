
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <memory> 
#include "./helpers/colors.hpp"
#include "./helpers/helpers.hpp"

#include "configFile.hpp"

using namespace uavos;


const Json& CConfigFile::GetConfigJSON()
{
    return  m_ConfigJSON;
}


void CConfigFile::initConfigFile (const char* fileURL)
{
    m_file_url = std::string(fileURL);

    CConfigFile::ReadFile (m_file_url.c_str());
    
    CConfigFile::ParseData (m_fileContents.str());
}


void CConfigFile::reloadFile ()
{
    CConfigFile::ReadFile (m_file_url.c_str());
    
    CConfigFile::ParseData (m_fileContents.str());
}



void CConfigFile::ReadFile (const char * fileURL)
{
    std::ifstream stream;
    std::cout << "Read config file: " << _LOG_CONSOLE_TEXT_BOLD_ << fileURL << "\033[0m ...." ;

    stream.open (fileURL , std::ifstream::in);
    if (!stream) {
        std::cout << _ERROR_CONSOLE_TEXT_ << " FAILED " << _NORMAL_CONSOLE_TEXT_ << std::endl;
        exit(1); // terminate with error
    }
    
    std::cout << _SUCCESS_CONSOLE_TEXT_ << " succeeded "  << _NORMAL_CONSOLE_TEXT_ << std::endl;
    
    m_fileContents.str("");
    m_fileContents <<  stream.rdbuf();
    
    std::cout << _SUCCESS_CONSOLE_TEXT_ << m_fileContents.str() << _NORMAL_CONSOLE_TEXT_ << std::endl;
    
    return ;
}

void CConfigFile::ParseData (std::string jsonString)
{

    m_ConfigJSON = Json::parse(removeComments(jsonString));
    
}