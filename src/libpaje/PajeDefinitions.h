/*
    This file is part of PajeNG

    PajeNG is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PajeNG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with PajeNG. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __PAJE_DEFINITIONS_H__
#define __PAJE_DEFINITIONS_H__
#include <string>
#include <map>
#include <set>
#include "PajeEnum.h"

typedef std::map<std::string,PajeEventId> event_name_to_id_t;
typedef std::map<PajeEventId,std::string> id_to_event_name_t;
typedef std::map<std::string,PajeFieldType> field_name_to_type_t;
typedef std::map<PajeFieldType,std::string> type_to_field_name_t;
typedef std::map<std::string,PajeField> field_name_to_id_t;
typedef std::map<PajeField,std::string> id_to_field_name_t;

class PajeDefinitions {
 private:
  field_name_to_id_t fieldNameToID;
  id_to_field_name_t idToFieldName;

  event_name_to_id_t eventNameToID;
  id_to_event_name_t idToEventName;

  field_name_to_type_t fieldNameToType;
  type_to_field_name_t typeToFieldName;

 public:
  std::map<PajeEventId,std::set<PajeField> > obligatoryFields;
  std::map<PajeEventId,std::set<PajeField> > optionalFields;

 public:
  PajeDefinitions (bool strict);
  ~PajeDefinitions ();

  const std::string &eventNameFromID (PajeEventId event);
  const std::string &fieldNameFromID (PajeField field);
  const std::string &fieldTypeNameFromID (PajeFieldType type);

  PajeEventId idFromEventName (std::string event);
  PajeField idFromFieldName (std::string field);
  PajeFieldType idFromFieldTypeName (std::string type);

  bool validEvent (PajeEventId event);
  bool validField (PajeField field);
  bool validFieldType (PajeFieldType field);

 private:
  void initialize (bool strict);
};

#endif
