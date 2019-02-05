require "sqlite3"
require 'sinatra'

db = SQLite3::Database.new "../database/lto_sample_data"

get '/' do
	a = []
	db.execute( "select * from cars" ) do |row|
		a << row
	end
	a.to_json
end
