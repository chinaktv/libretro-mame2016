// license:BSD-3-Clause
// copyright-holders:Ryan Holtz
//==================================================================
//
//  valueuniformreader.cpp - BGFX chain entry value mapper reader
//
//==================================================================

#include "valueuniformreader.h"

#include "entryuniform.h"
#include "valueuniform.h"

bgfx_entry_uniform* value_uniform_reader::read_from_value(const Value& value, std::string prefix, bgfx_uniform* uniform)
{
	validate_parameters(value, prefix);

	float values[4];
	int count = 1;
	if (value["value"].IsNumber())
	{
		values[0] = float(value["value"].GetDouble());
	}
	else
	{
		const Value& value_array = value["value"];
		count = int(value_array.Size());
		for (int i = 0; i < count; i++)
		{
			values[i] = float(value_array[i].GetDouble());
		}
	}
	return new bgfx_value_uniform(uniform, values, count);
}

void value_uniform_reader::validate_parameters(const Value& value, std::string prefix)
{
    READER_ASSERT(value.HasMember("value"), (prefix + "Must have string value 'value' (what value is being assigned?)\n").c_str());
    READER_ASSERT(value["value"].IsArray() || value["value"].IsNumber(), (prefix + "Value 'value' must be numeric or an array\n").c_str());
}
